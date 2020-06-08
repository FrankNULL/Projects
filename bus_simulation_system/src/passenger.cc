/**
 * @file passenger.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>
#include <string>
#include "src/passenger.h"

int Passenger::count_ = 0;

// Passenger::Passenger(Stop * dest = NULL, std::string name = "Nobody") {
Passenger::Passenger(int destination_stop_id, std::string name) {
  name_ = name;
  destination_stop_id_ = destination_stop_id;
  wait_at_stop_ = 0;
  time_on_bus_ = 0;
  id_ = count_;
  count_++;
}

void Passenger::Update() {
  if ( IsOnBus() ) {
    time_on_bus_++;
  } else {
    wait_at_stop_++;
  }
}

void Passenger::GetOnBus() {
  time_on_bus_ = 1;
}

int Passenger::GetTotalWait() const {
  return wait_at_stop_ + time_on_bus_;
}

bool Passenger::IsOnBus() const {
  return time_on_bus_ > 0 ? true : false;
}

int Passenger::GetDestination() const {
  return destination_stop_id_;
}

void Passenger::Report(std::ostream& out) const {
  out << "Name: " << name_ << std::endl;
  out << "Destination: " << destination_stop_id_ << std::endl;
  out << "Total Wait: " << GetTotalWait() << std::endl;
  out << "\tWait at Stop: " << wait_at_stop_ << std::endl;
  out << "\tTime on bus: " << time_on_bus_ << std::endl;
}
