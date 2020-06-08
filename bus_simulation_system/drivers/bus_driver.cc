#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <string> //convert int to string for names

#include "bus.h"
#include "passenger.h"
#include "random_passenger_generator.h"
#include "route.h"
#include "stop.h"

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
  
  Route CC1_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC1_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  Route CC2_EB("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
  Route CC2_WB("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
  
  int cc1_counter = 10000;
  int cc2_counter = 20000;
  
  Bus campus_connector1(std::to_string(cc1_counter), &CC1_EB, &CC1_WB, 60, 1);
  Bus campus_connector2(std::to_string(cc2_counter), &CC2_WB, &CC2_EB, 60, 1);
    
  std::cout << "/*\n *\n * Initial Report\n *\n*/" << std::endl;
  std::cout  << "\t*** Bus Reports ***" << std::endl << std::endl;
  campus_connector1.Report(std::cout);
  campus_connector2.Report(std::cout);
  
  std::cout  << std::endl << "\t*** Stop Reports ***" << std::endl << std::endl;
  std::cout  << std::endl << "\t\t ~ Eastbound ~ " << std::endl << std::endl;
  
  for(std::list<Stop *>::const_iterator it = CC_EB_stops_list.begin(); it != CC_EB_stops_list.end(); it++) {
    (*it)->Report(std::cout);
  }
  
  std::cout  << std::endl << "\t\t ~ Westbound ~ " << std::endl << std::endl;
  for(std::list<Stop *>::const_iterator it = CC_WB_stops_list.begin(); it != CC_WB_stops_list.end(); it++) {
    (*it)->Report(std::cout);
  }
  
  for (int i = 0; i < rounds; i++) {
    std::cout << "/*\n **\n ***\n **** Generation #" << (i+1) << "\n ***\n **\n */" << std::endl;
  
    CC1_EB.Update();
    CC1_WB.Update();
    campus_connector1.Update();
    campus_connector2.Update();
    
    if (campus_connector1.IsTripComplete()) {
      cc1_counter++;
      CC1_EB = Route("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
      CC1_WB = Route("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
      campus_connector1 = Bus(std::to_string(cc1_counter), &CC1_EB, &CC1_WB, 60, 1);
    }
    if (campus_connector2.IsTripComplete()) {
      cc2_counter++;
      CC2_EB = Route("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
      CC2_WB = Route("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
      campus_connector1 = Bus(std::to_string(cc2_counter), &CC2_EB, &CC2_WB, 60, 1);
    }
    
    std::cout  << "\t*** Bus Reports ***" << std::endl << std::endl;
    campus_connector1.Report(std::cout);
    campus_connector2.Report(std::cout);
  
    std::cout  << std::endl << "\t*** Stop Reports ***" << std::endl << std::endl;
    std::cout  << std::endl << "\t\t ~ Eastbound ~ " << std::endl << std::endl;
    
    for(std::list<Stop *>::const_iterator it = CC_EB_stops_list.begin(); it != CC_EB_stops_list.end(); it++) {
      (*it)->Report(std::cout);
    }
    
    std::cout  << std::endl << "\t\t ~ Westbound ~ " << std::endl << std::endl;
    for(std::list<Stop *>::const_iterator it = CC_WB_stops_list.begin(); it != CC_WB_stops_list.end(); it++) {
      (*it)->Report(std::cout);
    }
    
    std::cout << std::endl << std::endl;
  }

  return 0;
}