//
// Created by User on 2024. 02. 13..
//

#include <iostream>
#include <limits>
#include "Application.h"
#include "simulation_library/Simulator.h"
#include "UserPrompt.hpp"
void Application::run() {
  Simulator simulator;
  double cellSize = getUserInputNonNegativeDouble(userPrompts["cellSize"]);
  int pictureStartingPointX = getUserInputInt(userPrompts["pictureStartingPointX"]);
  int pictureStartingPointY = getUserInputInt(userPrompts["pictureStartingPointY"]);
  int pictureWidth = getUserInputNonNegativeInt(userPrompts["pictureWidth"]);
  int pictureHeight = getUserInputNonNegativeInt(userPrompts["pictureHeight"]);
  int emitterPointX = getUserInputInt(userPrompts["emitterPointX"]);
  int emitterPointY = getUserInputInt(userPrompts["emitterPointY"]);
  std::vector<std::pair<int, int>> targetPoints;
  static int targetPointCounter = 0;
  while(getUserInputBoolean(userPrompts["additionalTargetPoint"])) {
    int targetPointX = getUserInputInt(userPrompts["targetPointX"] +
        std::to_string(targetPointCounter));
    int targetPointY = getUserInputInt(userPrompts["targetPointY"] +
        std::to_string(targetPointCounter));
    targetPoints.push_back({targetPointX, targetPointY});
    targetPointCounter++;
  }
  std::string outPutFilePath;
  if(getUserInputBoolean(userPrompts["needCustomFilePath"])) {
    outPutFilePath = getUserInputString(userPrompts["filePath"]);
    simulator.run(cellSize, emitterPointX, emitterPointY, pictureStartingPointX,
                  pictureStartingPointY, pictureWidth, pictureHeight, targetPoints, outPutFilePath);
  }
  else {
    simulator.run(cellSize, emitterPointX, emitterPointY, pictureStartingPointX,
                  pictureStartingPointY, pictureWidth, pictureHeight, targetPoints);
  }
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
