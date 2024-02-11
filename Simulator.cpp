//
// Created by User on 2024. 02. 11..
//

#include <iostream>
#include "Simulator.h"
void Simulator::run() {
  setupConfiguration();
}
void Simulator::setupConfiguration() {
  getCellSize();
  createEmitterPoint();
  createTargetPoints();
  createStartingPoint();
  createPicture();
  configuration.setupSimulationSpace();
}
void Simulator::createEmitterPoint() {
  int emitterPointX = 0;
  int emitterPointY = 0;
  std::cout << "Please enter an integer as the x coordinate of emitter point (F)." << std::endl;
  while(!(std::cin >> emitterPointX)) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  std::cout << "Please enter an integer as the y coordinate of emitter point (F)." << std::endl;
  while(!(std::cin >> emitterPointY)) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  std::unique_ptr<Cell> emitterPoint = std::make_unique<Cell>(emitterPointX, emitterPointY);
  configuration.setEmitterPoint(std::move(emitterPoint));
}
void Simulator::createTargetPoints() {
  static int targetPointCounter = 0;
  int targetPointX = 0;
  int targetPointY = 0;
  std::cout<< "Please enter an integer as the x coordinate for target point (D"<<targetPointCounter<<")" << std::endl;
  while(!(std::cin >> targetPointX)) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  std::cout<< "Please enter an integer as the y coordinate for target point (D"<<targetPointCounter<<")" << std::endl;
  while(!(std::cin >> targetPointY)) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  std::unique_ptr<Cell> targetPoint = std::make_unique<Cell>(targetPointX, targetPointY);
  configuration.addTargetPoint(std::move(targetPoint));
  std::cout << "Do you wish to enter more target points? Press 0 for no. Press any other number for yes" << std::endl;
  int input = 0;
  if((std::cin >> input) && input) {
    targetPointCounter++;
    createTargetPoints();
  }
}
void Simulator::createStartingPoint() {
  int startingPointX = 0;
  int startingPointY = 0;
  std::cout << "Please enter an integer as the x coordinate of starting point (S)." << std::endl;
  while(!(std::cin >> startingPointX)) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  std::cout << "Please enter an integer as the y coordinate of starting point (S)." << std::endl;
  while(!(std::cin >> startingPointY)) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  std::unique_ptr<Cell> startingPoint = std::make_unique<Cell>(startingPointX, startingPointY);
  configuration.setStartingPoint(std::move(startingPoint));
}
void Simulator::getCellSize() {
  int cellSize = 0;
  std::cout << "Please enter an integer as the size of a cell (pixel)" << std::endl;
  while(!(std::cin >> cellSize)) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  configuration.setCellSize(cellSize);
}
void Simulator::createPicture() {
  int width = 0;
  int height = 0;
  std::cout << "How many cell should the picture width be" << std::endl;
  while(!(std::cin >> width) && width > 0) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  std::cout << "How many cell should the picture height be" << std::endl;
  while(!(std::cin >> height) && height > 0) {
    std::cout << "Please enter a valid integer" << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
  }
  configuration.setPictureHeight(height);
  configuration.setPictureWidth(width);
}
