//
// Created by User on 2024. 02. 11..
//

#include <iostream>
#include <valarray>
#include "Simulator.h"
#include "Calculator.h"
void Simulator::run(std::shared_ptr<Configuration> config) {
  configuration = std::move(config);
  Calculator calculator(configuration);
  FileWriter fileWriter;
  double distanceTravelledInPicture;
  std::vector<std::unique_ptr<Cell>> visitedCells;
  for(int i = 0; i < configuration->getTargetPoints().size(); i++) {
    calculator.calculateResult(configuration->getTargetPoints().at(i), i,
                               distanceTravelledInPicture, visitedCells);
    fileWriter.logResult("Distance traveled in picture, from F to D" + std::to_string(i) +
    " : " + std::to_string(distanceTravelledInPicture) + visitedCellsToString(std::move(visitedCells)),
    configuration->getOutputFilePath());
  }
}
std::string Simulator::visitedCellsToString(std::vector<std::unique_ptr<Cell>> visitedCells) {
  std::string resultString{". Visited cells: "};
  for(const auto& cell : visitedCells) {
    resultString += " x: "  + std::to_string(cell->getX()) + " y: " + std::to_string(cell->getY());
  }
  return resultString;
}
