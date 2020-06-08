/**
 * @file random_passenger_generator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/random_passenger_generator.h"

std::minstd_rand0 RandomPassengerGenerator::my_rand(time(0));

// Nothing to do here, just pass args along
RandomPassengerGenerator::RandomPassengerGenerator(std::list<double> probs,
    std::list<Stop *> stops) : PassengerGenerator(probs, stops) {}

/*
 *  GeneratePassengers uses the route's passenger generation probabilities per stop to determine how many passengers to create.
 *  Each probability is a double, i.e., .90 for a 90% probability of a passenger arriving at a stop for this bus route.
 *  While the probability is > .0001 (.01%), we attempt to generate passengers. Each time, we multiply the probability by itself, reduing the likelihood of additional passengers each time.
 *  This controls for multiple passengers arriving at a given time.
 *  Once the probability drops below .0001, we end our generation cycle for the stop.
 */

int RandomPassengerGenerator::GeneratePassengers() {
  int passengers_added = 0;
  std::list<double>::iterator prob_iter;
  std::list<Stop *>::iterator stop_iter;
  stop_iter = stops_.begin();
  int stop_index = (*stop_iter)->GetId();  // used for passenger generation
  stop_iter = stops_.end();
  stop_iter--;
  int last_stop_index = (*stop_iter)->GetId();
  // TODO(Staff): check for accuracy
  std::cout << "Time to generate!" << std::endl;
  for (prob_iter = generation_probabilities_.begin(),
                          stop_iter = stops_.begin();
       prob_iter != generation_probabilities_.end()
                    && stop_iter != stops_.end();
       prob_iter++, stop_iter++) {
    // get this stop's probability
    double initial_generation_probability = *prob_iter;
    double current_generation_probability = initial_generation_probability;

    // while there is still a (>.01%) chance of generating a passenger, try
    while (current_generation_probability > .0001
            && stop_index != last_stop_index) {
      // generate a random double value_comp
      double generation_value =
               ((my_rand() - my_rand.min()) / (my_rand.max() * 1.0));
      // e.g. `.54234234 < .90`, generate a passenger
      // `.912353254 !< .90`, don't generate
      // this gives us a 90% chance of creating a passenger
      if (generation_value < current_generation_probability) {
        // use the passenger factory to determine the destination
        // return value is 1 if passenger was added, 0 if it wasn't
        Passenger * tmp = PassengerFactory::
                          Generate(stop_index,
                                 last_stop_index);
        passengers_added += (*stop_iter)->AddPassengers(tmp);
      }
      // whether you generated or not, square the probability (reducing it)
      current_generation_probability *= initial_generation_probability;
    }
    stop_index++;
  }

  return passengers_added;
}
