#include <iostream>
#include <vector>

#include "passenger.h"

int main() {

  std::vector<Passenger *> passengers;
  
  passengers.push_back(new Passenger(33, "Zoe"));
  passengers.push_back(new Passenger(42, "Kaylee"));
  passengers.push_back(new Passenger(50, "Wash"));
  passengers.push_back(new Passenger(10, "Mal"));
  passengers.push_back(new Passenger(23, "Jayne"));

  
  int time = 1;
  
  while (time < 60) {
    
    std::cout << "/***********/" << std::endl;
    //std::cout << "/*         */" << std::endl;
    std::cout << "/* TIME ";
    if (time < 10) { std::cout << "0"; }
    std::cout << time;
    std::cout << " */" << std::endl;
    //std::cout << "/*         */" << std::endl;
    std::cout << "/***********/" << std::endl;
    
    for(std::vector<Passenger *>::iterator it = passengers.begin(); it != passengers.end(); it++) {
      if ((*it)->GetDestination() != time) {
        (*it)->Update();
      }
      else {
        Passenger * departing_passenger = *it;
        (*it)->GetOnBus();
        departing_passenger->Report(std::cout);
        
        //When removing the passenger, the iterator gets incremented to the next element.
        //We need to push it back so that the for loop increment places the iterator at
        // the correct next element.
        it = passengers.erase(it);
        it--;
        delete departing_passenger;
      }
    }
    
    time++;
  }
  
  return 0;
}