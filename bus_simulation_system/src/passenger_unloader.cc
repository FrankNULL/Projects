/**
 * @file passenger_unloader.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/passenger_unloader.h"

int PassengerUnloader::UnloadPassengers(std::list<Passenger *> passengers,
                                        Stop * current_stop) {
  // TODO(wendt): may need to do end-of-life here
  // instead of in Passenger or Simulator
  int passengers_unloaded = 0;
  std::ostringstream foo;  // output stream
  FileWriterManager* fwm = new FileWriterManager;  // FileWriterManager
  FileWriter* fw = fwm->Getinstance();
  for (std::list<Passenger *>::iterator it = passengers.begin();
      it != passengers.end();
      it++) {
    if ((*it)->GetDestination() == current_stop->GetId()) {
      // call report function to output stream
      (*it)->Report(foo);
      // write to the file
      fw->Write(passenger_file_name, Util::processOutput(foo));
      it = passengers.erase(it);
      // getting seg faults, probably due to reference deleted objects
      // here
      it--;

      passengers_unloaded++;
    }
  }

  return passengers_unloaded;
}
