//
// Created by User on 2024. 02. 11..
//

#include "FileWriter.h"
#include <fstream>
#include <iostream>
#include <vector>
void FileWriter::logResult(const std::string& result, const std::vector<std::unique_ptr<Cell>>& visitedCells,
                           const std::string& filePath) {
    std::ofstream outputFile(filePath, std::ios::app);
  if(outputFile.is_open()) {
    outputFile << result << ". Visited cells: ";
    for(const auto& visitedCell : visitedCells) {
      outputFile << " x: " << visitedCell->getX() << " y: " << visitedCell->getY();
    }
    outputFile << std::endl;
  }
  else {
    std::cerr<< "an unexpected error occurred" << std::endl;
  }
  outputFile.close();
}
