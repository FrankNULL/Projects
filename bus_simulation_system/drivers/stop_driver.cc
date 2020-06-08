#include <iostream>
#include <vector>

#include "bus.h"
#include "passenger.h"
#include "stop.h"
#include "random_passenger_generator.h" //needed now that bus is complete


int main() {

  std::vector<Passenger *> passengers;
  passengers.push_back(new Passenger(33, "Zoe"));
  passengers.push_back(new Passenger(42, "Kaylee"));
  passengers.push_back(new Passenger(50, "Wash"));
  passengers.push_back(new Passenger(10, "Mal"));
  passengers.push_back(new Passenger(23, "Jayne"));
  
  Stop stop1(1); //student union station
  Stop stop2(2, 44.973820, -93.227117); //Oak St & Washington Ave
  
  //Early iteration of Route class
  //Bus * bus1 = new Bus(1, new Route()[] {&stop1, &stop2}, new Route()[] {&stop2, &stop1});

  Stop ** stops1 = new Stop *[2] {&stop1, &stop2};
  std::list<Stop *> stops_list1;
  stops_list1.push_back(&stop1);
  stops_list1.push_back(&stop2);
  Stop ** stops2 = new Stop *[2] {&stop2, &stop1};
  std::list<Stop *> stops_list2;
  stops_list2.push_back(&stop2);
  stops_list2.push_back(&stop1);
  
  //only because these are identical, we reuse;
  double * distances = new double[1] {10};
  //double * distances2 = new double[1] {10}; //shown as example
  std::list<double> probabilities;
  //std::list<double> probabilities2; //shown as example
  probabilities.push_back(.5);
  probabilities.push_back(0); //ALWAYS needs to be zero
  
  Route * route1 = new Route("Route1", stops1, distances, 2, new RandomPassengerGenerator(probabilities, stops_list1));
  Route * route2 = new Route("Route2", stops2, distances, 2, new RandomPassengerGenerator(probabilities, stops_list2));
  
  Bus * bus1 = new Bus("10001", route1, route2);
  
  stop1.AddPassengers(passengers[0]);
  stop2.AddPassengers(passengers[1]);
  stop2.AddPassengers(passengers[2]);
  
  stop1.Update();
  stop2.Update();
  
  std::cout << "/*\n *\n * Initial Report\n *\n*/" << std::endl;
  
  stop1.Report(std::cout);
  stop2.Report(std::cout);
  
  std::cout << "/*\n *\n * Loading passengers onto Bus1\n *\n*/" << std::endl;
  
  stop1.LoadPassengers(bus1);
  passengers[0]->GetOnBus();
  
  stop1.Update();
  stop2.Update();
  passengers[0]->Update();
  
  std::cout << "/*\n *\n * Second Report\n *\n*/" << std::endl;
  
  stop1.Report(std::cout);
  stop2.Report(std::cout);
  
  std::cout << "/*\n *\n * Adding additional passengers to stop\n *\n*/" << std::endl;
  
  stop2.AddPassengers(passengers[3]);
  stop1.AddPassengers(passengers[4]);
  
  stop1.Update();
  stop2.Update();
  
  std::cout << "/*\n *\n * Third Report\n *\n*/" << std::endl;
  
  stop1.Report(std::cout);
  stop2.Report(std::cout);
  
  std::cout << "/*\n *\n * Loading passengers from both stops to Bus1\n *\n*/" << std::endl;
  
  stop1.LoadPassengers(bus1);
  stop2.LoadPassengers(bus1);

  passengers[1]->GetOnBus();
  passengers[2]->GetOnBus();
  passengers[3]->GetOnBus();
  passengers[4]->GetOnBus();
  
  stop1.Update();
  stop2.Update();
  
  passengers[0]->Update();
  passengers[1]->Update();
  passengers[2]->Update();
  passengers[3]->Update();
  passengers[4]->Update();
  
  std::cout << "/*\n *\n * Final Report\n *\n*/" << std::endl;
  
  stop1.Report(std::cout);
  stop2.Report(std::cout);
  
  std::cout << "/*----------------\n *\n * Post-mortem Passenger Reports\n *\n---------------*/" << std::endl;
  
  passengers[0]->Report(std::cout);
  passengers[1]->Report(std::cout);
  passengers[2]->Report(std::cout);
  passengers[3]->Report(std::cout);
  passengers[4]->Report(std::cout);
  
  return 0;
}