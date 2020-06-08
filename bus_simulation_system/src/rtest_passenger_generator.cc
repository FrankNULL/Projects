/**
 * @file rtest_passenger_generator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/rtest_passenger_generator.h"

// Nothing to do here, just pass args along
RtestPassengerGenerator::RtestPassengerGenerator(std::list<double> probs,
    std::list<Stop *> stops) : PassengerGenerator(probs, stops) {}

/*
 * This method adds one passenger at each stop every time generation occurs
 * You could build a formula based on stop index / count to add a 
 * passenger to alternate stops each time through the loop or figure
 * out some other way to generate the same number of passengers
 * each time the simulation is run
 */

int RtestPassengerGenerator::GeneratePassengers() {
  int passengers_added = 0;

  std::list<Stop *>::iterator stop_iter;
  stop_iter = stops_.begin();
  int stop_index = (*stop_iter)->GetId();  // used for passenger generation
  stop_iter = stops_.end();
  stop_iter--;
  int last_stop_index = (*stop_iter)->GetId();  // get the last stop index

  std::cout << "Time to generate!" << std::endl;
  int count = 0;
  for (stop_iter = stops_.begin();
    (*stop_iter)->GetId() < last_stop_index; stop_iter++) {
      stop_index = (*stop_iter)->GetId();
      for (int i =0 ; i< stop_index+1 ; i++) {
        Passenger * tmp = PassengerFactory::Generate(stop_index,
                                 last_stop_index);
        passengers_added += (*stop_iter)->AddPassengers(tmp);
        count++;
       }
  }
  return passengers_added;
}
