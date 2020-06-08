#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>

#include "passenger.h"
#include "stop.h"
#include "route.h"
#include "random_passenger_generator.h"


  /*Route(Stop * stops, double * distances, int num_stops, PassengerGenerator *);

  //Copy Constructor - Prototype pattern
  //Route(const Route &r);
  
  void Update();
  bool IsAtEnd() const;
  Stop * GetDestinationStop() const;
  double GetTotalRouteDistance() const;
  Stop * ToNextStop() const;
  double GetNextStopDistance() const;
 private:
  int GenerateNewPassengers();			//generates passengers on its route*/


int main() {
    
  int rounds = 50; //Number of rounds of generation to simulate in test
  
  srand((long)time(NULL)); //Seed the random number generator...

  //Stop ** all_stops = new Stop *[12];
  Stop ** CC_EB_stops = new Stop *[6];
  Stop ** CC_WB_stops = new Stop *[6];
  std::list<Stop *> CC_EB_stops_list;  
  std::list<Stop *> CC_WB_stops_list;
  
  //Eastbound stops
  Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
  Stop stop_CC_EB_2(1); //student union station
  Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_EB_4(3, 45, -94); //before transit
  Stop stop_CC_EB_5(4, 46, -95); //st paul 1
  Stop stop_CC_EB_6(5, 47, -96); //st paul 2
  
  //Westbound stops
  Stop stop_CC_WB_1(6, 47, -96); //st paul 2
  Stop stop_CC_WB_2(7, 46, -95); //st paul 1
  Stop stop_CC_WB_3(8, 45, -94); //before transit
  Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
  Stop stop_CC_WB_5(10); //student union station
  Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
  
  CC_EB_stops_list.push_back(&stop_CC_EB_1);
  CC_EB_stops[0] = &stop_CC_EB_1;
  CC_EB_stops_list.push_back(&stop_CC_EB_2);
  CC_EB_stops[1] = &stop_CC_EB_2;
  CC_EB_stops_list.push_back(&stop_CC_EB_3);
  CC_EB_stops[2] = &stop_CC_EB_3;
  CC_EB_stops_list.push_back(&stop_CC_EB_4);
  CC_EB_stops[3] = &stop_CC_EB_4;
  CC_EB_stops_list.push_back(&stop_CC_EB_5);
  CC_EB_stops[4] = &stop_CC_EB_5;
  CC_EB_stops_list.push_back(&stop_CC_EB_6);
  CC_EB_stops[5] = &stop_CC_EB_6;
  CC_WB_stops_list.push_back(&stop_CC_WB_1);
  CC_WB_stops[0] = &stop_CC_WB_1;
  CC_WB_stops_list.push_back(&stop_CC_WB_2);
  CC_WB_stops[1] = &stop_CC_WB_2;
  CC_WB_stops_list.push_back(&stop_CC_WB_3);
  CC_WB_stops[2] = &stop_CC_WB_3;
  CC_WB_stops_list.push_back(&stop_CC_WB_4);
  CC_WB_stops[3] = &stop_CC_WB_4;
  CC_WB_stops_list.push_back(&stop_CC_WB_5);
  CC_WB_stops[4] = &stop_CC_WB_5;
  CC_WB_stops_list.push_back(&stop_CC_WB_6);
  CC_WB_stops[5] = &stop_CC_WB_6;
  
  double * CC_EB_distances = new double[5];
  double * CC_WB_distances = new double[5];
  CC_EB_distances[0] = 5;
  CC_EB_distances[1] = 4;
  CC_EB_distances[2] = 3;
  CC_EB_distances[3] = 10;
  CC_EB_distances[4] = 6;
  
  CC_WB_distances[0] = 6;
  CC_WB_distances[1] = 10;
  CC_WB_distances[2] = 3;
  CC_WB_distances[3] = 4;
  CC_WB_distances[4] = 5;
  
  
  std::list<double> CC_EB_probs;  //realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15); //WB
  CC_EB_probs.push_back(.3); //CMU
  CC_EB_probs.push_back(.025); //O&W
  CC_EB_probs.push_back(.05); //Pre-transit
  CC_EB_probs.push_back(.05); //STP 1
  CC_EB_probs.push_back(0); //STP 1
  //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
  //        remove possibility of generating passengers with nowhere to go
  
  std::list<double> CC_WB_probs; //realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35); //stp 2
  CC_WB_probs.push_back(.05); //stp 1
  CC_WB_probs.push_back(.01); //post-transit
  CC_WB_probs.push_back(.01); //O&W
  CC_WB_probs.push_back(.02); //CMU
  CC_WB_probs.push_back(0); //WB
  
  
  RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  
  Route CC_EB("Campus Connector - Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC_WB("Campus Connector - Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  
  Bus campus_connector("00001", &CC_EB, &CC_WB, 60, 1);
    
  std::cout << "/*\n *\n * Initial Report\n *\n*/" << std::endl;
  
  CC_EB.Update();
  CC_WB.Update();
    
  std::cout  << std::endl << "\t*** Route Reports ***" << std::endl << std::endl;
  std::cout  << std::endl << "\t\t ~ Eastbound ~ " << std::endl << std::endl;
  CC_EB.Report(std::cout);
  std::cout  << std::endl << "\t\t ~ Westbound ~ " << std::endl << std::endl;
  CC_WB.Report(std::cout);
  
  int EB_distance = 1; //starting at the first stop in the route
  int WB_distance = 1; //will start at the first stop in the route (which is the last stop in the prior route)
  
  int passengers_loaded_on_bus = 0;
  
  for (int i = 0; i < rounds; i++) {
    std::cout << "/*\n **\n ***\n **** Generation #" << (i+1) << "\n ***\n **\n */" << std::endl;
  
    CC_EB.Update();
    CC_WB.Update();
    
    //Bus move
    if (EB_distance != -1) {
      EB_distance--;
    } else {
      WB_distance--;
    }
    
    if (EB_distance == 0) {
      if (CC_EB.IsAtEnd()) {
        EB_distance = -1;
      }
      Stop * stop_arrived_at = CC_EB.GetDestinationStop();
      std::cout << std::endl << "Passengers getting on at: " << stop_arrived_at->GetId() << std::endl << std::endl;
      passengers_loaded_on_bus += stop_arrived_at->LoadPassengers(&campus_connector);
      CC_EB.ToNextStop();
      EB_distance = CC_EB.GetNextStopDistance();
    }
    else if (WB_distance == 0) {
      if (CC_WB.IsAtEnd()) {
        WB_distance = -1;
      }
      Stop * stop_arrived_at = CC_WB.GetDestinationStop();
      std::cout << std::endl << "Passengers getting on at: " << stop_arrived_at->GetId() << std::endl << std::endl;
      passengers_loaded_on_bus += stop_arrived_at->LoadPassengers(&campus_connector);
      CC_WB.ToNextStop();
      WB_distance = CC_WB.GetNextStopDistance();
    }
    else if (EB_distance != -1) {
      std::cout << std::endl << "Distance to next stop: " << EB_distance << std::endl << std::endl;
    }
    else {
      std::cout << std::endl << "Distance to next stop: " << WB_distance << std::endl << std::endl;
    }
    
    std::cout  << std::endl << "\t*** Route Reports ***" << std::endl << std::endl;
    std::cout  << std::endl << "\t\t ~ Eastbound ~ " << std::endl << std::endl;
    CC_EB.Report(std::cout);
    std::cout  << std::endl << "\t\t ~ Westbound ~ " << std::endl << std::endl;
    CC_WB.Report(std::cout);
    
    std::cout << std::endl << std::endl;

  }

  std::cout << "*\n*\n*\n*\n*\t PASSENGERS LOADED ONTO BUS *\n*\n*\n*\n*\n" << std::endl;
  std::cout << passengers_loaded_on_bus << std::endl;
  
  return 0;
}