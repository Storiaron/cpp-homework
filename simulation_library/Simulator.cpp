//
// Created by User on 2024. 02. 11..
//

#include <iostream>
#include <valarray>
#include "Simulator.h"
void Simulator::run(double cellSize, int emitterPointX, int emitterPointY, int pictureStartingPointX,
                    int pictureStartingPointY, int pictureWidth, int pictureHeight,
                    std::vector<std::pair<int, int>> targetPointCoordinates, const std::string& filePath) {
  setupConfiguration(cellSize, emitterPointX, emitterPointY, pictureStartingPointX,
                     pictureStartingPointY, pictureWidth, pictureHeight, targetPointCoordinates);
  for(int i = 0; i < targetPointCoordinates.size(); i++) {
    calculateAndLogResult(std::make_shared<Cell>(targetPointCoordinates.at(i).first,
                                                 targetPointCoordinates.at(i).second), i, filePath);
  }
}
void Simulator::setupConfiguration(double cellSize, int emitterPointX, int emitterPointY, int pictureStartingPointX,
                                   int pictureStartingPointY, int pictureWidth, int pictureHeight,
                                   std::vector<std::pair<int, int>> targetPointCoordinates) {
  configuration.setCellSize(cellSize);
  configuration.setEmitterPoint(std::make_shared<Cell>(emitterPointX, emitterPointY));
  configuration.setPictureHeight(pictureHeight);
  configuration.setPictureWidth(pictureWidth);
  configuration.setPictureStartingPoint(std::make_shared<Cell>(pictureStartingPointX, pictureStartingPointY));
  std::vector<std::shared_ptr<Cell>> targetPoints;
  for(const auto& targetPointCoordinate : targetPointCoordinates) {
    targetPoints.push_back(std::make_shared<Cell>(targetPointCoordinate.first, targetPointCoordinate.second));
  }
  configuration.setTargetPoints(targetPoints);
}
void Simulator::calculateAndLogResult(const std::shared_ptr<Cell>& targetPoint, int targetPointCounter, const std::string& filePath) {
  const static double EPSILON = 0.001;
  std::vector<std::unique_ptr<Cell>> visitedCells;
  double directionVectorX = 0, directionVectorY = 0;
  calculateDirectionVector(directionVectorX, directionVectorY, targetPoint);
  double distanceResult = 0;
  double startingPointX = configuration.getEmitterPoint()->getX();
  double startingPointY = configuration.getEmitterPoint()->getY();
  double currentPointX = startingPointX;
  double currentPointY = startingPointY;
  bool isInPicture;
  while(std::sqrt(std::pow(currentPointX - targetPoint->getX(), 2) +
      std::pow(currentPointY - targetPoint->getY(), 2)) > EPSILON) {
    isInPicture = configuration.isInPicture(currentPointX, currentPointY);
    if(isInPicture) {
      distanceResult += std::sqrt(std::pow(directionVectorX, 2) + std::pow(directionVectorY, 2)) * configuration.getCellSize();
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
  fileWriter.logResult("Distance in picture, from F to D" +std::to_string(targetPointCounter) + ": "
  + std::to_string(distanceResult), visitedCells, filePath);
}
void Simulator::calculateDirectionVector(double& directionVectorX, double& directionVectorY,
                                const std::shared_ptr<Cell>& targetPoint) {
  double distanceX = (targetPoint->getX() - configuration.getEmitterPoint()->getX()) * configuration.getCellSize();
  double distanceY = (targetPoint->getY() - configuration.getEmitterPoint()->getY()) * configuration.getCellSize();
  double squaredEuclideanDistance = std::pow(distanceX, 2) + std::pow(distanceY, 2);
  directionVectorX = distanceX / squaredEuclideanDistance;
  directionVectorY = distanceY / squaredEuclideanDistance;
}
