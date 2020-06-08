/**
 * @file bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/bus_factory.h"
#include <ctime>
// global ocnstant for counter
static int STG1_count = 0;
static int STG2_count = 0;
static int STG3_count = 0;

// bus fac generate method
// to generate a type of bus as we want
Bus* BusFactory::Generate(std::string name) {
    if (type_ == "small") {
        return new SmallBus(name, outbound_, inbound_, speed_);
    } else if (type_ == "medium") {
        return new MediumBus(name, outbound_, inbound_, speed_);
    } else if (type_ == "large") {
        return new LargeBus(name, outbound_, inbound_, speed_);
    } else {
        std::cout << "type_: " << type_ << std::endl;
        throw "Type must be small, medium or large";
    }
}

/*
  *@brief Strategy 1 repeat like small, regular, small, regular..
  */
class Strategy1:public Strategy {
 public:
  Bus* BusDepotGenerate(std::string name, Route* outbound, Route*
        inbound, double speed) override {
        if (STG1_count % 2 == 0) {
            STG1_count++;
             std::cout << "Generate Small Bus" << std::endl;
            return new SmallBus(name, outbound, inbound, speed);
        } else {
            STG1_count++;
            std::cout << "Generate Medium Bus" << std::endl;
            return new MediumBus(name, outbound, inbound, speed);
        }
  }
};
/*
  *@brief Strategy 2 repeat like regular, large, regular, large..
  */
class Strategy2:public Strategy {
 public:
  Bus* BusDepotGenerate(std::string name, Route* outbound, Route*
        inbound, double speed) override {
        // medium case
        if (STG2_count % 2 == 0) {
            STG2_count++;
            std::cout << "Generate Medium Bus" << std::endl;
            return new MediumBus(name, outbound, inbound, speed);
        // large case
        } else {
            STG2_count++;
            std::cout << "Generate Large Bus" << std::endl;
            return new LargeBus(name, outbound, inbound, speed);
        }
  }
};
/*
  *@brief Strategy 3 repeat like small, regular, large, small, regular, large..
  */
class Strategy3:public Strategy {
 public:
  Bus* BusDepotGenerate(std::string name, Route* outbound, Route*
        inbound, double speed) override{
      // small case
      if (STG3_count % 3 == 0) {
        STG3_count++;
         std::cout << "Generate Small Bus" << std::endl;
        return new SmallBus(name, outbound, inbound, speed);
      } else if (STG3_count % 3 == 1) {
        STG3_count++;
         std::cout << "Generate Medium Bus" << std::endl;
        return new MediumBus(name, outbound, inbound, speed);
      } else {
        STG3_count++;
         std::cout << "Generate Large Bus" << std::endl;
        return new LargeBus(name, outbound, inbound, speed);
      }
  }
};
/*
  *@brief bd_generate() method to create different size of buses based on time
  */
Bus* BusDepot::bd_generate() {
    Strategy* strategy[3];
    strategy[0] = new Strategy1;
    strategy[1] = new Strategy2;
    strategy[2] = new Strategy3;

    time_t t = time(NULL);
    struct tm buf;
    struct tm* current_time = localtime_r(&t, &buf);
    int hour = current_time -> tm_hour;

    if (hour >= 6 && hour < 8) {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Strategy 1" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        return strategy[0] -> BusDepotGenerate(
            name_, outbound_, inbound_, speed_);
    } else if (hour >= 8 && hour < 15) {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Strategy 2" << std::endl;
        std::cout << "-----------------------------" << std::endl;
       return strategy[1] -> BusDepotGenerate(
           name_, outbound_, inbound_, speed_);
    } else if (hour >= 15 && hour < 20) {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Strategy 3" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        return strategy[2] ->BusDepotGenerate(
            name_, outbound_, inbound_, speed_);
    } else {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Strategy 4: only small" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        return new Bus(name_, outbound_, inbound_, 30, 1);
    }
}
