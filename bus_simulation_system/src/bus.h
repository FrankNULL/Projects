/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/data_structs.h"

#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/IObservable.h"
#include "src/util.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

/*
*@brief IBus class as the interface
*/
class IBus{
 public:
  virtual void changeColor(int a, int b, int c, int d) = 0;
  virtual void changeDensity(int d) = 0;
};

/*
*@brief BusDecorator class inherit from IBus
*/
class BusDecorator: public IBus {
 protected:
  IBus *m_Bus;
 public:
  explicit BusDecorator(IBus *baseBus): m_Bus(baseBus) {}
  /*
  *@brief changeColor() method to change color
  *@param a : red
  *@param b : green
  *@param c : blue
  *@param d : alpha
  */
  void changeColor(int a, int b, int c, int d) override {
    m_Bus-> changeColor(a, b, c, d);
  }
  /*
  *@brief changeDensity() method to change density
  *@param d : alpha
  */
  void changeDensity(int d) override {
    m_Bus-> changeDensity(d);
  }
};


/**
 * @brief The main class for thegeneration of buses.
 *
 * Calls to \ref Bus constructor to creat new bus object
 * This class contains all the bus related function.
 */
class Bus:public IObservable <BusData*>, public IBus{
 public:
 /**
    * @brief bus constrcutor
    *
    * @param name bus name
    * @param outbound bus route goes outward
    * @param inbound bus route goes inward
    * @param speed bus speed
    * @param type bus type
    *
    * @return Bus object with the type we want and name, route in, route out, and speed.
    */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                double speed = 1, std::string type = "Medium");
  bool IsTripComplete();
  bool LoadPassenger(Passenger *);  // returning revenue delta
  bool Move();
  void Update();
  virtual void Report(std::ostream&);

  // Vis Getters
  void UpdateBusData();
  BusData GetBusData() const;
  std::string GetName() const { return name_; }
  Stop * GetNextStop() const { return next_stop_; }
  size_t GetNumPassengers() const { return passengers_.size(); }
  int GetCapacity() const { return passenger_max_capacity_; }

  /*
  *@brief changeColor() method to set color
  *@param a : red
  *@param b : green
  *@param c : blue
  *@param d : alpha
  */
  void changeColor(int a = 255, int b = 0, int c = 0, int d = 255) override {
    bus_data_.color.red = a;
    bus_data_.color.green = b;
    bus_data_.color.blue = c;
    bus_data_.color.alpha = d;
  }
  /*
  *@brief changeDensity() method to change density
  *@param d : alpha
  */
  void changeDensity(int d) {
    bus_data_.color.alpha = d;
  }
  /*
  *@brief changeDensity() method to change density
  *@param d : alpha
  */
  void clearall() {
    passengers_.clear();
  }

  /*
  *@brief check if a bus is outbound or not to color it
  */
  bool isOutbound();

 private:
  int UnloadPassengers();  // returning revenue delta
  int HandleBusStop();
  void ToNextStop();
  double UpdateDistance();
  Route* CurrentRoute();
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  std::string type_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete
  // Vis data for bus
  BusData bus_data_;

 protected:
  int total_passenger = 0;  // add total passenger number
};
#endif  // SRC_BUS_H_
