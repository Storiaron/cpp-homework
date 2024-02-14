//
// Created by User on 2024. 02. 11..
//

#ifndef CPP_HOMEWORK__SIMULATOR_H_
#define CPP_HOMEWORK__SIMULATOR_H_

#include <vector>
#include "Cell.h"
#include "Configuration.h"
#include "FileWriter.h"
#include "Calculator.h"
class Simulator {
 public:
  void run(std::shared_ptr<Configuration> config);
 private:
  std::shared_ptr<Configuration> configuration;
  std::string visitedCellsToString(std::vector<std::unique_ptr<Cell>> visitedCells);
};

#endif //CPP_HOMEWORK__SIMULATOR_H_
