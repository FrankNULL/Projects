/**
 * @file bus_type.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_TYPES_H_
#define SRC_BUS_TYPES_H_
#include <string>
#include "./bus.h"
/**
 * @brief generaete small bus class
 */
class SmallBus : public Bus {
 public:
    /**
    * @brief small bus constrcutor 
    *
    * @param name bus name
    * @param outbound bus route goes outward
    * @param inbound bus route goes inward
    * @param speed bus speed
    *
    * @return Bus object with the type we want and name, route in, route out, and speed.
    */
    SmallBus(std::string name, Route* out, Route* in, double speed):
        Bus(name, out, in, 30, speed, "Small") { }
};
/**
 * @brief generaete medium bus class
 */
class MediumBus : public Bus {
 public:
    /**
    * @brief medium bus constrcutor 
    *
    * @param name bus name
    * @param outbound bus route goes outward
    * @param inbound bus route goes inward
    * @param speed bus speed
    *
    * @return Bus object with the type we want and name, route in, route out, and speed.
    */
    MediumBus(std::string name, Route* out, Route* in, double speed):
        Bus(name, out, in, 60, speed, "Medium") { }
};
/**
 * @brief generaete large bus class
 */
class LargeBus : public Bus {
 public:
 /**
  * @brief large bus constrcutor 
  *
  * @param name bus name
  * @param outbound bus route goes outward
  * @param inbound bus route goes inward
  * @param speed bus speed
  *
  * @return Bus object with the type we want and name, route in, route out, and speed.
  */
    LargeBus(std::string name, Route* out, Route* in, double speed):
        Bus(name, out, in, 90, speed, "Large") { }
};

#endif  // SRC_BUS_TYPES_H_
