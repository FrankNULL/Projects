/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <string>

#include "./bus.h"
#include "./bus_types.h"
/**
 * @brief Bus class to generate the bus and related work
 */

class BusFactory {
 public:
    /**
    * @brief bus factory constrcutor 
    *
    * @param type bus type s, m, l.
    * @param outbound bus route goes outward
    * @param inbound bus route goes inward
    * @param speed bus speed
    *
    * @return Bus object with the type we want and name, route in, route out, and speed.
    */
    BusFactory(std::string type, Route* outbound, Route*
    inbound, double speed) :
        type_(type), outbound_(outbound), inbound_(inbound),
        speed_(speed) { }
    Bus* Generate(std::string name);

 private:
    std::string type_;
    Route* inbound_;
    Route* outbound_;
    double speed_;
};

/**
 * @brief BusDepot class employ different stretegy to generate buses
 */

class BusDepot {
 public:
    /**
    * @brief bus depot constrcutor  
    *
    * @param name  bus name
    * @param outbound bus route goes outward
    * @param inbound bus route goes inward
    * @param speed bus speed
    *
    * @return BusDepot object with the type we want and name, route in, route out, and speed.
    */
    BusDepot(std::string name, Route* outbound, Route*
        inbound, double speed): name_(name), outbound_(outbound),
            inbound_(inbound), speed_(speed) { }
    /**
    * @brief bd_generate method to generate bus using Strategy 
    *
    * @return a bus based on Strategy we use  
    */
    Bus * bd_generate();

 protected:
    std::string name_;
    Route* inbound_;
    Route* outbound_;
    double speed_;
};

/**
 * @brief Strategy class to choose different size of bus at different time
 */
class Strategy {
 public:
 /**
  * @brief BusDepotGenerate method of Strategy  
  *
  * @param name bus name 
  * @param outbound bus route goes outward
  * @param inbound bus route goes inward
  * @param speed bus speed
  *
  * @return Bus object with the name, route in, route out, and speed.
  */
  virtual Bus * BusDepotGenerate(std::string name, Route* outbound, Route*
        inbound, double speed) = 0;
};

#endif   // SRC_BUS_FACTORY_H_
