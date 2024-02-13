//
// Created by User on 2024. 02. 13..
//

#include <iostream>
#include <limits>
#include "Application.h"
#include "simulation_library/Simulator.h"
void Application::run() {
  double cellSize = getUserInputNonNegativeDouble("Enter the size of a cell");
  int pictureStartingPointX = getUserInputInt("Enter the x coordinate of picture starting point (S)");
  int pictureStartingPointY = getUserInputInt("Enter the y coordinate of picture starting point (S)");
  int pictureWidth = getUserInputNonNegativeInt("How many cell width should the picture be");
  int pictureHeight = getUserInputNonNegativeInt("How many cell tall should the picture be");
  int emitterPointX = getUserInputInt("Enter the x coordinate of the emitter point (F)");
  int emitterPointY = getUserInputInt("Enter the y coordinate of the emitter point (F)");
  std::vector<std::pair<int, int>> targetPoints;
  static int targetPointCounter = 0;
  while(getUserInputBoolean("Do you wish to add more target points (D) (Y|N)?")) {
    int targetPointX = getUserInputInt("Enter the x coordinate of target point (D" +
        std::to_string(targetPointCounter) + ")");
    int targetPointY = getUserInputInt("Enter the y coordinate of target point (D" +
        std::to_string(targetPointCounter) + ")");
    targetPoints.push_back({targetPointX, targetPointY});
  }
  Simulator simulator;
  simulator.run(cellSize, emitterPointX, emitterPointY, pictureStartingPointX,
                pictureStartingPointY, pictureWidth, pictureHeight, targetPoints);

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