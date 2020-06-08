/**
 * @file util.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/util.h"

// process incoming data for parse
std::vector<std::string> Util::processOutput(std::ostringstream& foo) {
  std::vector<std::string> container;
  std::string content = foo.str();
  std::string line;
  std::istringstream boo(content);
  // counter
  int count = 0;
  // seperate each line
  while (std::getline(boo, line, '\n')) {
      count++;
      std::istringstream goo(line);
      std::string str;
      // seperate a line with : sign
      while (std::getline(goo, str, ':')) {
         container.push_back(str);
      }
  }
  return container;
}

// write the data in the container to the file
void FileWriter::Write(std::string filename,
    std::vector<std::string> container) {
    // open a file
    std::ofstream outfile;
    outfile.open(filename, std::ios_base::app);
    int count = 0;
    // if it is for bus
    if (filename.compare("BusData.csv") == 0) {
        for (auto it = std::begin(container); it != std::end(container); ++it) {
           outfile << *it << ",";
           count++;
           // for each 11 items add a new line
           if (count % 11 ==0) {
             outfile << "\n";
           }
        }
    }
    // if it is for passenger
    if (filename.compare("PassData.csv") == 0) {
        for (auto it = std::begin(container); it != std::end(container); ++it) {
           outfile << *it << ",";
           count++;
           // for each ten items add a newline
           if (count % 10 == 0) {
             outfile << "\r\n";
           }
        }
    }
    // close file
    outfile.close();
}

// singleton pattern
FileWriter * FileWriterManager::file_writer = nullptr;
FileWriter* FileWriterManager :: Getinstance() {
    // if filewriter is null
    // assign a pointer to it
    if (!file_writer) {
        file_writer = new FileWriter;
    }
    return file_writer;
}
