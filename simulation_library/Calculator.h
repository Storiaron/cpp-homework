//
// Created by User on 2024. 02. 14..
//

#ifndef CPP_HOMEWORK_SIMULATION_LIBRARY_CALCULATOR_H_
#define CPP_HOMEWORK_SIMULATION_LIBRARY_CALCULATOR_H_

#include "Cell.h"
#include "Configuration.h"
class Calculator {
 public:
  Calculator(std::shared_ptr<Configuration> configuration) : configuration(configuration) {};
  void calculateResult(const std::shared_ptr<Cell>& targetPoint, int targetPointCounter,
                       double& distanceTravelledInPicture, std::vector<std::unique_ptr<Cell>>& visitedCells);
 private:
  void calculateDirectionVector(double& directionVectorX, double& directionVectorY,
                                            const std::shared_ptr<Cell>& targetPoint);
  std::shared_ptr<Configuration> configuration;
};

#endif //CPP_HOMEWORK_SIMULATION_LIBRARY_CALCULATOR_H_
