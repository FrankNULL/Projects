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



#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"
#include "../src/passenger_unloader.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StopTests : public ::testing::Test {
protected:

  Stop *stop, *stop1, *stop2;
    
  virtual void SetUp() {

  }

  virtual void TearDown() {
   
    delete stop;
    stop = NULL;
  
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(StopTests, Constructor) {
  stop = new Stop(5, 12.89, 3.14);
  EXPECT_EQ(stop->GetId(), 5);
  EXPECT_EQ(stop->GetLatitude(), 3.14);
  EXPECT_EQ(stop->GetLongitude(), 12.89);

  stop1 = new Stop(20, 9.2, 11.08);
  EXPECT_EQ(stop1->GetId(), 20);
  EXPECT_EQ(stop1->GetLatitude(), 11.08);
  EXPECT_EQ(stop1->GetLongitude(), 9.2); 

  stop2 = new Stop(16, 8.31, 20.22);
  EXPECT_EQ(stop2->GetId(), 16);
  EXPECT_EQ(stop2->GetLatitude(), 20.22);
  EXPECT_EQ(stop2->GetLongitude(), 8.31);  
};


