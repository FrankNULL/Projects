/**
 * @file util.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
/**
 * @brief The main class for parse data
 */
class Util {
 public:
  /*
  *@brief processOutput() method to parse data
  *@param foo : ostringstream
  */
    static std::vector<std::string> processOutput(std::ostringstream& foo);
};
/**
 * @brief The main class for writing to the file
 */
class FileWriter {
 public:
  /*
  *@brief Write() method to write data to file
  *@param file_name : file name
  *@param container: string vector to be written 
  */
  void Write(std::string file_name, std::vector<std::string> container);
};
/**
 * @brief The main class for manage file writer
 */
class FileWriterManager {
 private:
  static FileWriter* file_writer;

 public:
  /*
  *@brief Getinstance() method to get an instance of file writter
  */
  static FileWriter*  Getinstance();
};

#endif  // SRC_UTIL_H_
