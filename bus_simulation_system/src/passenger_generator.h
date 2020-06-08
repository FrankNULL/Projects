/**
 * @file passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_GENERATOR_H_
#define SRC_PASSENGER_GENERATOR_H_

#include <list>
#include "src/passenger_factory.h"
#include "src/stop.h"

class Stop;  // forward declaration

class PassengerGenerator {
 public:
  PassengerGenerator(std::list<double>, std::list<Stop *>);
  // Makes the class abstract, cannot instantiate and forces subclass override
  virtual int GeneratePassengers() = 0;  // pure virtual
 protected:
  std::list<double> generation_probabilities_;
  std::list<Stop *> stops_;

  // should we be using a singleton here somehow?
  // PassengerFactory * pass_factory;
};
#endif  // SRC_PASSENGER_GENERATOR_H_
