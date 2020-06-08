/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete passenger;
    passenger = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, constructor) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);

  TearDown();
};

TEST_F(PassengerTests, constructor_name_) {
  passenger = new Passenger();
  passenger1 = new Passenger(12,"John Doe");
  passenger2 = new Passenger(12,"Apple Bee");
  std::string expected_output_0 = "Name: Nobody"; 
  std::string expected_output_1 = "Name: John Doe";
  std::string expected_output_2 = "Name: Apple Bee";

  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output0 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger1->Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger2->Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();

  int p0 = output0.find(expected_output_0);
  int p1 = output1.find(expected_output_1);
  int p2 = output2.find(expected_output_2);
  EXPECT_GE(p0, 0);
  EXPECT_GE(p1, 0);
  EXPECT_GE(p2, 0);

  TearDown();
  delete passenger1;
  passenger1 = NULL;
  delete passenger2;
  passenger2 = NULL;
};

TEST_F(PassengerTests, constructor_wait_at_stop_) {
  passenger = new Passenger();
  std::string expected_output_0 = "\tWait at Stop: 0"; 
  std::string expected_output_1 = "\tWait at Stop: 4"; 
  std::string expected_output_2 = "\tWait at Stop: 7"; 
 
  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output0 = testing::internal::GetCapturedStdout();

  passenger->Update();
  passenger->Update(); 
  passenger->Update(); 
  passenger->Update(); 

  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();

  passenger->Update();
  passenger->Update(); 
  passenger->Update(); 

  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();

  int p0 = output0.find(expected_output_0);
  int p1 = output1.find(expected_output_1);
  int p2 = output2.find(expected_output_2);
  EXPECT_GE(p0, 0);
  EXPECT_GE(p1, 0);
  EXPECT_GE(p2, 0);

  TearDown();
};


TEST_F(PassengerTests, constructor_time_on_bus_) {
  passenger = new Passenger();
  std::string expected_output_0 = "\tTime on bus: 0"; 
  std::string expected_output_1 = "\tTime on bus: 1"; 
  std::string expected_output_2 = "\tTime on bus: 4"; 
  std::string expected_output_3 = "\tTime on bus: 10"; 

  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output0 = testing::internal::GetCapturedStdout();
  passenger->GetOnBus();

  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  passenger->Update();
  passenger->Update(); 
  passenger->Update(); 
  
  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  passenger->Update();
  passenger->Update(); 
  passenger->Update(); 
  passenger->Update(); 
  passenger->Update(); 
  passenger->Update(); 
  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output3 = testing::internal::GetCapturedStdout();

  int p0 = output0.find(expected_output_0);
  int p1 = output1.find(expected_output_1);
  int p2 = output2.find(expected_output_2);
  int p3 = output3.find(expected_output_3);
  EXPECT_GE(p0, 0);
  EXPECT_GE(p1, 0);
  EXPECT_GE(p2, 0);
  EXPECT_GE(p3, 0);

  TearDown();
};



TEST_F(PassengerTests, GetTotalWait ) {
  passenger = new Passenger();

  EXPECT_EQ(passenger->GetTotalWait(), 0);
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 4);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 5);  
  passenger->Update();  
  passenger->Update();
  passenger->Update();
  passenger->Update();
  passenger->Update();
  EXPECT_EQ(passenger->GetTotalWait(), 10); 

  passenger1 = new Passenger(10, "Annie");
  EXPECT_EQ(passenger1->GetTotalWait(), 0);
  passenger1->Update();
  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 2);
  passenger1->GetOnBus();
  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 4); 

  TearDown();
  delete passenger1;
  passenger1 = NULL;
};


TEST_F(PassengerTests, GetOnBus) {
  passenger = new Passenger();
  std::string expected_output_0 = "\tTime on bus: 0";
  std::string expected_output_1 = "\tTime on bus: 1"; 

  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output0= testing::internal::GetCapturedStdout();

  int p0 = output0.find(expected_output_0);
  EXPECT_GE(p0, 0);

  passenger ->GetOnBus();
  
  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output1= testing::internal::GetCapturedStdout(); 

  int p1 = output1.find(expected_output_1);
  EXPECT_GE(p1, 0);


  passenger1 = new Passenger(20, "Annie");
  std::string expected_output_2 = "\tTime on bus: 0";
  std::string expected_output_3 = "\tTime on bus: 1"; 

  testing::internal::CaptureStdout();
  passenger1->Report(std::cout);
  std::string output2= testing::internal::GetCapturedStdout();

  int p2 = output2.find(expected_output_2);
  EXPECT_GE(p2, 0);

  passenger1 ->GetOnBus();
  
  testing::internal::CaptureStdout();
  passenger1->Report(std::cout);
  std::string output3= testing::internal::GetCapturedStdout(); 

  int p3 = output3.find(expected_output_3);
  EXPECT_GE(p3, 0);


  passenger2 = new Passenger(12, "Bob");
  std::string expected_output_4 = "\tTime on bus: 0";
  std::string expected_output_5 = "\tTime on bus: 1"; 

  testing::internal::CaptureStdout();
  passenger2->Report(std::cout);
  std::string output4= testing::internal::GetCapturedStdout();

  int p4 = output4.find(expected_output_0);
  EXPECT_GE(p4, 0);

  passenger2 ->GetOnBus();
  
  testing::internal::CaptureStdout();
  passenger2->Report(std::cout);
  std::string output5= testing::internal::GetCapturedStdout(); 

  int p5 = output5.find(expected_output_1);
  EXPECT_GE(p5, 0);

  TearDown();
  delete passenger1;
  passenger1 = NULL;
  delete passenger2;
  passenger2 = NULL;
};




TEST_F(PassengerTests, GetDestination) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetDestination(), -1);
  passenger1 = new Passenger(10);
  EXPECT_EQ(passenger1->GetDestination(), 10);
  passenger2 = new Passenger(34);
  EXPECT_EQ(passenger2->GetDestination(), 34);  

  TearDown();
  delete passenger2;
  passenger2 = NULL;
  delete passenger1;
  passenger1 = NULL;
};

TEST_F(PassengerTests, Report) {
  passenger = new Passenger();
  passenger1 = new Passenger(12,"John Doe");
  std::string expected_output_0 = "Name: Nobody"; 
  std::string expected_output_1 = "Destination: -1";
  std::string expected_output_2 = "Total Wait: 0";
  std::string expected_output_3 = "\tTime on bus: 0";
  std::string expected_output_4 = "\tWait at Stop: 0";

  std::string expected_output_5 = "Name: John Doe"; 
  std::string expected_output_6 = "Destination: 12";
  std::string expected_output_7 = "Total Wait: 0";
  std::string expected_output_8 = "\tTime on bus: 0";
  std::string expected_output_9 = "\tWait at Stop: 0"; 


  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output0 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger1->Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();


  int p0 = output0.find(expected_output_0);
  int p1 = output0.find(expected_output_1);
  int p2 = output0.find(expected_output_2);
  int p3 = output0.find(expected_output_3);
  int p4 = output0.find(expected_output_4);

  int p5 = output1.find(expected_output_5);
  int p6 = output1.find(expected_output_6);
  int p7 = output1.find(expected_output_7);
  int p8 = output1.find(expected_output_8);
  int p9 = output1.find(expected_output_9);

  EXPECT_GE(p0, 0);
  EXPECT_GE(p1, 0);
  EXPECT_GE(p2, 0);
  EXPECT_GE(p3, 0);
  EXPECT_GE(p4, 0);
  EXPECT_GE(p5, 0);
  EXPECT_GE(p6, 0);
  EXPECT_GE(p7, 0);
  EXPECT_GE(p8, 0);
  EXPECT_GE(p9, 0);

  passenger->Update();
  passenger->Update();

  passenger1->Update();
  passenger1->Update();
  passenger1->GetOnBus();
  passenger1->Update();
  passenger1->Update();
  passenger1->Update();

  std::string expected_output_10 = "Name: Nobody"; 
  std::string expected_output_11 = "Destination: -1";
  std::string expected_output_12 = "Total Wait: 2";
  std::string expected_output_13 = "\tTime on bus: 0";
  std::string expected_output_14 = "\tWait at Stop: 2";

  std::string expected_output_15 = "Name: John Doe"; 
  std::string expected_output_16 = "Destination: 12";
  std::string expected_output_17 = "Total Wait: 6";
  std::string expected_output_18 = "\tTime on bus: 4";
  std::string expected_output_19 = "\tWait at Stop: 2"; 
  
  testing::internal::CaptureStdout();
  passenger->Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger1->Report(std::cout);
  std::string output3 = testing::internal::GetCapturedStdout();

  
  int p10 = output2.find(expected_output_10);
  int p11 = output2.find(expected_output_11);
  int p12 = output2.find(expected_output_12);
  int p13 = output2.find(expected_output_13);
  int p14 = output2.find(expected_output_14);
  int p15 = output3.find(expected_output_15);
  int p16 = output3.find(expected_output_16);
  int p17 = output3.find(expected_output_17);
  int p18 = output3.find(expected_output_18);
  int p19 = output3.find(expected_output_19);

  EXPECT_GE(p10, 0);
  EXPECT_GE(p11, 0);
  EXPECT_GE(p12, 0);
  EXPECT_GE(p13, 0);
  EXPECT_GE(p14, 0);
  EXPECT_GE(p15, 0);
  EXPECT_GE(p16, 0);
  EXPECT_GE(p17, 0);
  EXPECT_GE(p18, 0);
  EXPECT_GE(p19, 0);

  TearDown();
  delete passenger1;
  passenger1 = NULL;
};
