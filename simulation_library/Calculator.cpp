//
// Created by User on 2024. 02. 14..
//

#include <memory>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Calculator.h"
#include "Cell.h"
void Calculator::calculateResult(const std::shared_ptr<Cell>& targetPoint, int targetPointCounter,
                                 double& distanceTravelledInPicture, std::vector<std::unique_ptr<Cell>>& visitedCells) {
  const static double EPSILON = 0.001;
  double directionVectorX = 0, directionVectorY = 0;
  calculateDirectionVector(directionVectorX, directionVectorY, targetPoint);
  double distanceResult = 0;
  double startingPointX = configuration->getEmitterPoint()->getX();
  double startingPointY = configuration->getEmitterPoint()->getY();
  double currentPointX = startingPointX;
  double currentPointY = startingPointY;
  bool isInPicture;
  while(std::sqrt(std::pow(currentPointX - targetPoint->getX(), 2) +
      std::pow(currentPointY - targetPoint->getY(), 2)) > EPSILON) {
    isInPicture = configuration->isInPicture(currentPointX, currentPointY);
    if(isInPicture) {
      distanceResult += std::sqrt(std::pow(directionVectorX, 2) + std::pow(directionVectorY, 2)) * configuration->getCellSize();
      std::unique_ptr<Cell> visitedCell = std::make_unique<Cell>(std::floor(currentPointX), std::floor(currentPointY));
      auto duplicate = std::find_if(visitedCells.begin(), visitedCells.end(),
                                    [&visitedCell](const std::unique_ptr<Cell>& ptr) {
                                      return *ptr == *visitedCell;
                                    });

      if (duplicate == visitedCells.end()) {
        visitedCells.push_back(std::move(visitedCell));
      }
    }
    currentPointX += directionVectorX;
    currentPointY += directionVectorY;
  }
  if(configuration->isInPicture(targetPoint->getX(), targetPoint->getY())) {
    visitedCells.push_back(std::make_unique<Cell>(*targetPoint));
  }
  distanceTravelledInPicture = distanceResult;
}
void Calculator::calculateDirectionVector(double& directionVectorX, double& directionVectorY,
                                         const std::shared_ptr<Cell>& targetPoint) {
  double distanceX = (targetPoint->getX() - configuration->getEmitterPoint()->getX()) * configuration->getCellSize();
  double distanceY = (targetPoint->getY() - configuration->getEmitterPoint()->getY()) * configuration->getCellSize();
  double squaredEuclideanDistance = std::pow(distanceX, 2) + std::pow(distanceY, 2);
  directionVectorX = distanceX / squaredEuclideanDistance;
  directionVectorY = distanceY / squaredEuclideanDistance;
}