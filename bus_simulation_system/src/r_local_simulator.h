/**
 * @file r_local_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_R_LOCAL_SIMULATOR_H_
#define SRC_R_LOCAL_SIMULATOR_H_
#include <vector>
#include <string>
#include "src/simulator.h"

class rLocalSimulator : public Simulator {
 public:
   /**
    * @brief start method for LocalSimulator 
    * @return true or false to indicate if we success
    */
  bool Start() override;
  /**
    * @brief Update method for LocalSimulator 
    * @return true or false to indicate if we success
    */
  bool Update() override;
 private:
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
};

#endif  // SRC_R_LOCAL_SIMULATOR_H_
