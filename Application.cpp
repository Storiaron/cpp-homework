//
// Created by User on 2024. 02. 13..
//

#include <iostream>
#include <limits>
#include "Application.h"
#include "simulation_library/Simulator.h"
#include "UserPrompt.hpp"
#include "Configuration.h"
#include "Cell.h"
void Application::run() {
  Simulator simulator;
  std::shared_ptr<Configuration> configuration = std::make_unique<Configuration>();
  double cellSize = getUserInputNonNegativeDouble(userPrompts["cellSize"]);
  int pictureStartingPointX = getUserInputInt(userPrompts["pictureStartingPointX"]);
  int pictureStartingPointY = getUserInputInt(userPrompts["pictureStartingPointY"]);
  int pictureWidth = getUserInputNonNegativeInt(userPrompts["pictureWidth"]);
  int pictureHeight = getUserInputNonNegativeInt(userPrompts["pictureHeight"]);
  int emitterPointX = getUserInputInt(userPrompts["emitterPointX"]);
  int emitterPointY = getUserInputInt(userPrompts["emitterPointY"]);
  std::vector<std::shared_ptr<Cell>> targetPoints;
  static int targetPointCounter = 0;
  while(getUserInputBoolean(userPrompts["additionalTargetPoint"])) {
    int targetPointX = getUserInputInt(userPrompts["targetPointX"] +
        std::to_string(targetPointCounter));
    int targetPointY = getUserInputInt(userPrompts["targetPointY"] +
        std::to_string(targetPointCounter));
    targetPoints.push_back(std::make_shared<Cell>(targetPointX, targetPointY));
    targetPointCounter++;
  }
  if(getUserInputBoolean(userPrompts["needCustomFilePath"])) {
    configuration->setOutputFilePath(getUserInputString(userPrompts["filePath"]));
  }
  std::shared_ptr<Cell> pictureStartingPoint = std::make_shared<Cell>(pictureStartingPointX,pictureStartingPointY);
  std::shared_ptr<Cell> emitterPoint = std::make_shared<Cell>(emitterPointX,emitterPointY);
  configuration->setTargetPoints(targetPoints);
  configuration->setCellSize(cellSize);
  configuration->setPictureWidth(pictureWidth);
  configuration->setPictureHeight(pictureHeight);
  configuration->setEmitterPoint(emitterPoint);
  configuration->setPictureStartingPoint(pictureStartingPoint);
  simulator.run(std::move(configuration));
}
int Application::getUserInputInt(std::string userPrompt) {
  int input;
  std::cout << userPrompt << std::endl;
  while(!(std::cin >> input)) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return input;
}
int Application::getUserInputNonNegativeInt(std::string userPrompt) {
  int input;
  std::cout << userPrompt << std::endl;
  while(!(std::cin >> input) || input < 0) {
    std::cout << "Please enter a valid non-negative integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return input;
}
double Application::getUserInputNonNegativeDouble(std::string userPrompt) {
  double input;
  std::cout << userPrompt << std::endl;
  while(!(std::cin >> input) || input < 0) {
    std::cout << "Please enter a valid non-negative number" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return input;
}
bool Application::getUserInputBoolean(std::string userPrompt) {
  std::string input;
  std::cout << userPrompt << std::endl;
  while(!(std::cin >> input) ||(input != "Y" && input != "y" && input != "N" && input != "n")) {
    std::cout << "Enter Y/y for yes or N/n for no" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return input == "Y" || input == "y";
}
std::string Application::getUserInputString(std::string userPrompt) {
  std::string input;
  std::cout << userPrompt << std::endl;
  while(!(std::cin >> input)) {
    std::cout << "Enter a valid string" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return input;
}
