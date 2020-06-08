/**
 * @file VisualizationSimulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>
#include <string>
#include "web_code/web/visualization_simulator.h"
#include "src/bus.h"
#include "src/route.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

// constructor
VisualizationSimulator::VisualizationSimulator(WebInterface* webI,
    ConfigManager* configM, std::ostream* out) {
    webInterface_ = webI;
    configManager_ = configM;
    paused_ = false;
    out_ = out;
}

VisualizationSimulator::~VisualizationSimulator() {
}
/*
*@brief TogglePause() method to pause
*/
void VisualizationSimulator::TogglePause() {
    std::cout << "Toggling Pause" << std::endl;
    paused_ = !paused_;
}
/*
*@brief VisualizationSimulator() method to start the simulation
*@param busStartTimings : start timing
*@param numTimeSteps : number of steps to run
*/
void VisualizationSimulator::Start(const std::vector<int>& busStartTimings,
    const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }
    simulationTimeElapsed_ = 0;
    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(*out_);
        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}

/*
*@brief Update() method to update
*/
bool VisualizationSimulator::Update() {
    // Code called to update simulator. Will first check if
    // we are in a state where we can update (e.g., not paused, not finished)
    // then call ExecuteUpdate() to actually call update if possible
    // return whether or not ExecuteUpdate() was called
    bool can_update = CanUpdate();
    if (can_update) {
        ExecuteUpdate();
    }
    return can_update;
}

/*
*@brief CanUpdate() method to check if it is paused
*/
bool VisualizationSimulator::CanUpdate() {
    // Check whether or not simulator can update
    // maybe unable to update because paused, terminated, etcetra
    // only cares about whether or not it is paused right now
    return !paused_;
}
/*
*@brief ExecuteUpdate() method to execute update
*/
void VisualizationSimulator::ExecuteUpdate() {
    // This function has the same text as what Update() used to have
    // I added a gating mechanism for pause functionality
    simulationTimeElapsed_++;

    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;
    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {
            Route * outbound = prototypeRoutes_[2 * i];
            Route * inbound = prototypeRoutes_[2 * i + 1];
            BusDepot* bd = new BusDepot(std::to_string(busId),
                outbound->Clone(), inbound->Clone(), 1);
            // create a new bus
            Bus* newBus = bd -> bd_generate();
            // set its color
            IBus* decor = new BusDecorator(newBus);
            decor->changeColor(255, 255, 255, 102);
            // add to the bus list
            busses_.push_back(newBus);
            busId++;
            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }
    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;
    // create pointer to call methods
    FileWriterManager* fwm = new FileWriterManager;
    FileWriter* fw = fwm->Getinstance();
    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();
        // if it is in outbound, set maroon
        // if it is in inbound, set gold
        if (busses_[i]->isOutbound()) {
            IBus* decor = new BusDecorator(busses_[i]);
            decor->changeColor(128, 0, 0, 110);
            // based on passenger size set intensity
            int ratio  = (busses_[i]->GetBusData().num_passengers /
                                busses_[i]->GetBusData().capacity) * 140;
            decor->changeDensity(ratio + 110);
        } else {
            IBus* decor = new BusDecorator(busses_[i]);
            decor->changeColor(255, 215, 0, 110);
            // based on passenger size set intensity
            int ratio  = (busses_[i]->GetBusData().num_passengers /
                                busses_[i]->GetBusData().capacity) * 140;
            decor->changeDensity(ratio + 110);
        }

        // if trip is completed, output its info to BusData.cvs
        if (busses_[i]->IsTripComplete()) {
            std::ostringstream foo;
            webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
            busses_[i]->clearall();
            busses_[i]->Report(foo);
            fw->Write(bus_stats_file_name, Util::processOutput(foo));
            busses_.erase(busses_.begin() + i);
            continue;
        }

        webInterface_->UpdateBus(busses_[i]->GetBusData());
        busses_[i]->Report(std::cout);
    }
    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

        prototypeRoutes_[i]->Report(std::cout);
    }
}

// ClearListeners() method to clear all observers
void VisualizationSimulator::ClearListeners() {
    // Check whether or not simulator can update
    // maybe unable to update because paused, terminated, etcetra
    // only cares about whether or not it is paused right now
    if (paused_ != true) {
      for (std::vector <Bus*> :: iterator it = busses_.begin();
        it != busses_.end(); ++it) {
            (*it)->ClearObservers();
        }
    }
}
void VisualizationSimulator::ClearStopListeners() {
    // Check whether or not simulator can update
    // maybe unable to update because paused, terminated, etcetra
    // only cares about whether or not it is paused right now
    if (paused_ != true) {
      for (std::vector<Route*> :: iterator r = prototypeRoutes_.begin();
        r !=prototypeRoutes_.end(); ++r) {
            std::list <Stop*> stops = (*r)->GetStops();
        for (std::list<Stop*> :: iterator it = stops.begin();
            it != stops.end(); ++it) {
                (*it)->ClearObservers();
            }
      }
    }
}
// AddListener method for a bus
void VisualizationSimulator::AddListener(
    std::string* id, IObserver<BusData*>* observer) {
    // loop through the bus list
    for (std::vector <Bus*> :: iterator it = busses_.begin();
        it != busses_.end(); ++it) {
            std::string strNew = *id;  // convert string pointer
            // check id
            // if equal, add observer to this bus
            if ((*it)->GetBusData().id.compare(strNew) == 0) {
                (*it)->RegisterObservers(observer);
            }
        }
}
// AddListenerStop() method to add observers to a specific stop
void VisualizationSimulator::AddListenerStop(
    std::string* id, IObserver<Stop*>* observer) {
  // loop through the bus list
  for (std::vector<Route*> :: iterator r = prototypeRoutes_.begin();
        r !=prototypeRoutes_.end(); ++r) {
           std::list <Stop*> stops = (*r)->GetStops();
        for (std::list <Stop*> :: iterator it = stops.begin();
            it != stops.end(); ++it) {
            std::string strNew = *id;  // convert string pointer
            // check id
            // if equal, add observer to this bus
            if ((*it)->GetId() == std::stoi(strNew)) {
                (*it)->RegisterObservers(observer);
            }
        }
    }
}
