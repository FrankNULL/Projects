/**
 * @file simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_SIMULATOR_H_
#define SRC_SIMULATOR_H_

#include <list>
#include <vector>

#include "src/bus.h"
#include "src/stop.h"
#include "src/route.h"
#include "src/passenger_generator.h"

class Simulator {
 public:
  virtual bool Start() = 0;
  virtual bool Update() = 0;

 protected:
  // bus and stop list will be iterated over to update
  // ist is efficient in traversal
  std::list<Bus *> active_buses_;         // buses leave scope
  std::list<Stop *> all_stops_;

  // prototype_routes and distance lists will be accessed directly
  // list is not efficient at direct selection by index
  // routes below a for copying on bus creation
  std::vector<Route *> prototype_routes_;
  std::vector<double *> distance_between_sets_;
  std::vector<PassengerGenerator *> passenger_generators_;
  // std::vector<std:list<double>> passenger_generation_probability_lists;
};

#endif  // SRC_SIMULATOR_H_
