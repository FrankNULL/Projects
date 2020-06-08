/**
 * @file VisualizationSimulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef WEB_CODE_WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_CODE_WEB_VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>
#include "web_code/web/web_interface.h"
#include "src/config_manager.h"
#include "src/IObservable.h"
#include "src/bus_factory.h"
#include "src/util.h"
using std::cout;
class Route;
class Bus;
class Stop;

class VisualizationSimulator {
 public:
    VisualizationSimulator(WebInterface*, ConfigManager*, std::ostream*);
    ~VisualizationSimulator();

    void Start(const std::vector<int>&, const int&);
    bool Update();
    bool CanUpdate();
    void TogglePause();
    /**
    * @brief clear all observers to this bus
    */
    void ClearListeners();
    /**
    * @brief clear all observers to this stop
    */
    void ClearStopListeners();
    /**
    * @brief add all observers to this bus
    * @param id:  this bus's id
    * @param observer: observer to be added to this bus
    */
    void AddListener(std::string* id, IObserver<BusData*>* observer);
    /**
    * @brief add all observers to this bus
    * @param id:  this stop's id
    * @param observer: observer to be added to this bus
    */
    void AddListenerStop(std::string* id, IObserver<Stop*>* observer);


 private:
    void ExecuteUpdate();
    WebInterface* webInterface_;
    ConfigManager* configManager_;
    std::vector<int> busStartTimings_;
    std::vector<int> timeSinceLastBus_;
    int numTimeSteps_;
    int simulationTimeElapsed_;
    std::vector<Route *> prototypeRoutes_;
    std::vector<Bus *> busses_;

    int busId = 1000;
    bool paused_;
    std::ostream* out_;
    // file to be written
    std::string bus_stats_file_name = "BusData.csv";
};

#endif  // WEB_CODE_WEB_VISUALIZATION_SIMULATOR_H_
