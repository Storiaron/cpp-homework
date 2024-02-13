//
// Created by User on 2024. 02. 12..
//

#include <stdexcept>
#include <iostream>
#include "ConfigurationTester.h"
void ConfigurationTester::run() {
  if(!invalidInputSmallTest()) {
    std::cout << "Invalid input test with very small value failed." << std::endl;
  }
  if(!invalidInputDoubleTest()) {
    std::cout << "Invalid input test with double failed." << std::endl;
  }
  if(!invalidInputIntTest()) {
    std::cout << "Invalid input test with integer failed." << std::endl;
  }
  if(isInPictureTest(0,0,0,0, 1, 1)) {
    std::cout << "Is in picture test 1 failed, point should be outside the picture frame" << std::endl;
  }
  if(isInPictureTest(0, 10, 10, 10, 5.5432, 20)) {
    std::cout << "Is in picture test 2 failed, point should be outside the picture frame" << std::endl;
  }
  if(isInPictureTest(-10, 10, 10, 10, 3, 5)) {
    std::cout << "Is in picture test 3 failed, point should be outside the picture frame" << std::endl;
  }
  if(!isInPictureTest(0, 10, 5, 10, 3, 4)) {
    std::cout << "Is in picture test 4 failed, point should be inside the picture frame" << std::endl;
  }
  if(!isInPictureTest(0, 0, 10, 0, 3.4, 0)) {
    std::cout << "Is in picture test 5 failed, point should be inside the picture frame" << std::endl;
  }

  std::cout << "All configuration tests ran" << std::endl;
}
bool ConfigurationTester::invalidInputIntTest() {
  Configuration configuration;
  try {
    configuration.setPictureWidth(-1);
    return false;
  }
  catch(std::invalid_argument exception) {
    return true;
  }
}
bool ConfigurationTester::invalidInputDoubleTest() {
  Configuration configuration;
  try {
    configuration.setPictureWidth(-1.1);
    return false;
  }
  catch(std::invalid_argument exception) {
    return true;
  }
}
bool ConfigurationTester::invalidInputSmallTest() {
  Configuration configuration;
  try {
    configuration.setPictureWidth(-0.0000001);
    return false;
  }
  catch(std::invalid_argument exception) {
    return true;
  }
}
bool ConfigurationTester::isInPictureTest(int startingPointX, int startingPointY,
                                                  int width, int height, double pointX, double pointY) {
  Configuration configuration;
  configuration.setPictureStartingPoint(std::make_shared<Cell>(startingPointX, startingPointY));
  configuration.setPictureWidth(width);
  configuration.setPictureHeight(height);
  return configuration.isInPicture(pointX, pointY);
}
