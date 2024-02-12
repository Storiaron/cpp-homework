//
// Created by User on 2024. 02. 11..
//

#include "FileWriter.h"
#include <fstream>
#include <iostream>
void FileWriter::logResult(const std::string& result, const std::string& filePath) {
    std::ofstream outputFile(filePath, std::ios::app);
  if(outputFile.is_open()) {
    outputFile << result << std::endl;
  }
  else {
    std::cerr<< "an unexpected error occurred" << std::endl;
  }
  outputFile.close();
}