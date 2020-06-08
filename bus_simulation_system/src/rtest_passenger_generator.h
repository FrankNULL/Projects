/**
 * @file rtest_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_RTEST_PASSENGER_GENERATOR_H_
#define SRC_RTEST_PASSENGER_GENERATOR_H_

#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration

class RtestPassengerGenerator : public PassengerGenerator{
 public:
 /**
    * @brief constrcutor method for RtestPassengerGenerator
    * @param std::list<double> a double list
    * @param std::list<Stop *> a stop list
    * @return an RtestPassengerGenerator with a double and stop list 
    */
  RtestPassengerGenerator(std::list<double>, std::list<Stop *>);
 /**
    * @brief constrGeneratePassengerscutor method for RtestPassengerGenerator
    * @return an int indicate how many passengers we generate
    */ 
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_RTEST_PASSENGER_GENERATOR_H_
