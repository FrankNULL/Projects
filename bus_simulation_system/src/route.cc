/**
 * @file route.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/route.h"

Route::Route(std::string name, Stop ** stops, double * distances, int num_stops,
                                               PassengerGenerator * generator) {
  for (int i = 0; i < num_stops; i++) {
    stops_.push_back(stops[i]);
  }
  for (int i = 0; i < num_stops - 1; i++) {
    distances_between_.push_back(distances[i]);
  }

  name_ = name;
  generator_ = generator;
  num_stops_ = num_stops;
  // Need to see if this (next statement) is right. How does first stop work?
  destination_stop_index_ = 0;
  destination_stop_ = stops[0];
}

Route * Route::Clone() {
  // constructor needs Stop **, we have list<stop>
  Stop ** stops = new Stop *[stops_.size()];
  int stop_index = 0;
  for (auto* stop : stops_) {
    stops[stop_index++] = stop;
  }

  // constructor needs distance *, we have list<double>
  double * distances = new double[distances_between_.size()];
  int distance_index = 0;
  for (auto distance : distances_between_) {
    distances[distance_index++] = distance;
  }

  return new Route(name_, stops, distances, num_stops_, generator_);
}

void Route::Update() {
  GenerateNewPassengers();
  for (auto* stop : stops_) {
    stop->Update();
  }
  UpdateRouteData();
}

void Route::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Num stops: " << num_stops_ << std::endl;
  int stop_counter = 0;
  for (auto* stop : stops_) {
    if (stop_counter == destination_stop_index_) {
      out << "\t\t vvvvv Next Stop vvvvv" << std::endl;
    }
    stop->Report(out);
    stop_counter++;
  }
}

bool Route::IsAtEnd() const {
  return destination_stop_index_ >= num_stops_;
}

Stop * Route::PrevStop() {
    std::list<Stop *>::iterator iter = stops_.begin();

    if (destination_stop_index_ == 0) {
        return *iter;
    } else if (destination_stop_index_ < num_stops_) {
        std::advance(iter, destination_stop_index_ - 1);
        return *iter;
    } else {
        std::advance(iter, num_stops_ - 1);
        return *iter;
    }
}

void Route::ToNextStop() {
  destination_stop_index_++;

  if (destination_stop_index_ < num_stops_) {
    // operator[] promises efficient access to elements
    // Lists don't provide that (efficiently)
    // Can't use [] on lists
    std::list<Stop *>::const_iterator iter = stops_.begin();
    std::advance(iter, destination_stop_index_);
    destination_stop_ = *iter;
  } else {
      destination_stop_ = (*stops_.end());
      // std::list<Stop *>::const_iterator iter = stops_.begin();
      // std::advance(iter, num_stops_ - 1);
      // destination_stop_ = *iter;
  }
}

Stop * Route::GetDestinationStop() const {
  // Despite this being derived data (from destination_stop_index_ and stops_)
  // we store this, because [] does not exist for lists, and
  // std::advance is O(n)
  /* std::list<Stop *>::const_iterator iter = stops_.begin();
     std::advance(iter, destination_stop_index_);
     return *iter; //resolving the iterator gets you the Stop * from the list */
  return destination_stop_;
}

double Route::GetTotalRouteDistance() const {
  double total_distance = 0;
  for (auto distance : distances_between_) {
    total_distance += distance;
  }
  return total_distance;
}

double Route::GetNextStopDistance() const {
  if (destination_stop_index_ > 0) {
      std::list<double>::const_iterator iter = distances_between_.begin();
      std::advance(iter, destination_stop_index_-1);
      return *iter;  // resolving the iterator gets you the Stop * from the list
  // return distances_between_[destination_stop_index_ - 1];
  // CAN'T DO THIS (return statement above) ; see ToNextStop()
  } else {
        return 0;
    }
}

int Route::GenerateNewPassengers() {
  // returning number of passengers added by generator
  return generator_->GeneratePassengers();
}

void Route::UpdateRouteData() {
    route_data_.id = name_;

    std::vector<StopData> stopDataVec = std::vector<StopData>();
    for (auto* s : stops_) {
        StopData stopData;

        stopData.id = std::to_string(s->GetId());

        Position p;
        p.x = s->GetLongitude();
        p.y = s->GetLatitude();
        stopData.position = p;

        stopData.num_people = static_cast<int>(s->GetNumPassengersPresent());

        stopDataVec.push_back(stopData);
    }
    route_data_.stops = stopDataVec;
}

RouteData Route::GetRouteData() const {
    return route_data_;
}
