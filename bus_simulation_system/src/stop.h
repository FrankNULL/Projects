/**
 * @file Bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_STOP_H_
#define SRC_STOP_H_

#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"
#include "src/IObservable.h"
class Bus;

// observer pattern
// inherit IObservable class
class Stop : public IObservable <Stop*>{
 public:
  explicit Stop(int, double = 44.973723, double = -93.235365);
  int LoadPassengers(Bus *);  // Removing passengers from stop
  // and onto a bus
  int AddPassengers(Passenger *);  // Adding passengers
  // to the stop (from the generator)
  void Update();
  int GetId() const;
  void Report(std::ostream&) const;

  // Vis Getters
  double GetLongitude() const { return longitude_; }
  double GetLatitude() const { return latitude_; }
  size_t GetNumPassengersPresent() { return passengers_.size(); }

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};

#endif  // SRC_STOP_H_
