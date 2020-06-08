/* STUDENTS:  DO NOT EDIT THIS FILE.  INSTEAD, MODIFY YOUR OWN PROJECT
 * CODE TO FIT THE SPECIFICATION GIVEN BY THE TESTS IN THIS FILE.
 *
 * If you DO modify it, we overwrite it with a fresh version from our repo
 * when grading, so you can't use it to fudge the tests anyway.
 *
 * This file is used by the CS3081W auto-grading system.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>


#include "../src/bus.h"
#include "../src/route.h"
#include "../src/random_passenger_generator.h"
using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class RouteTests : public ::testing::Test {
 protected:
  Passenger* passenger;
  Stop** stops;
  Stop* stop1;
  double ps[1];
  RandomPassengerGenerator * generator1;

  Route *route;

      
  virtual void SetUp() {
    passenger = new Passenger();
    stop1 = new Stop(2, 4.2, 3.6);
    stops = new Stop*[1];
    stops[0] = stop1;
    ps[0] = 20.0;
    std::list<double> prob;
    std:: list<Stop*> stop2;
    generator1 = new RandomPassengerGenerator(prob, stop2);

  }


  virtual void TearDown() {
    delete route;
    route = NULL;
   
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(RouteTests, Constructor) {
  
   SetUp();

   route = new Route("UMN", stops, ps, 1, generator1);

   EXPECT_EQ(route-> GetName(), "UMN");
  
  std::string expected_output_0 = "Num stops: 1";
  testing::internal::CaptureStdout();
  route->Report(std::cout);
  std::string output0 = testing::internal::GetCapturedStdout(); 

  int p0 = output0.find(expected_output_0);
  EXPECT_GE(p0, 0);
  bool list_tester = true;
  std::list<Stop *> compareStop = route->GetStops();
  for (std::list<Stop*>::const_iterator it = compareStop.begin();
                                        it != compareStop.end(); it++) {
    if (!((*it)->GetId() == 2 && (*it)->GetLatitude() == 3.6 && (*it)->GetLongitude() == 4.2)) {
      list_tester = false;
    }
  }

  EXPECT_EQ(list_tester, true);


};

TEST_F(RouteTests, IsAtEnd) {
  SetUp();

  route = new Route("UMN", stops, ps, 1, generator1);
  EXPECT_EQ(route->IsAtEnd(), false);

  route->ToNextStop();

  EXPECT_EQ(route->IsAtEnd(), true);  

  TearDown();
};




