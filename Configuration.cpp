//
// Created by User on 2024. 02. 11..
//

#include "Configuration.h"
void Configuration::setEmitterPoint(std::shared_ptr<Cell> point) {
  setXMinMax(point->getX());
  setYMinMax(point->getY());
  this->emitterPoint = std::move(point);
}
void Configuration::setStartingPoint(std::shared_ptr<Cell> point) {
  setXMinMax(point->getX());
  setYMinMax(point->getY());
  this->startingPoint = std::move(point);
}
void Configuration::addTargetPoint(std::shared_ptr<Cell> point) {
  setXMinMax(point->getX());
  setYMinMax(point->getY());
  this->targetPoints.push_back(std::move(point));
}
void Configuration::setCellSize(int size) {
  this->cellSize = size;
}
void Configuration::setPictureHeight(int size) {
  this->pictureHeight = size;
}
void Configuration::setPictureWidth(int size) {
  this->pictureWidth = size;
}
void Configuration::setXMinMax(int candidateX) {
  this->xMax = std::max(this->xMax, candidateX);
  this->xMin = std::min(this->xMin, candidateX);
}
void Configuration::setYMinMax(int candidateY) {
  this->yMax = std::max(this->yMax, candidateY);
  this->yMin = std::min(this->yMin, candidateY);
}
void Configuration::setupSimulationSpace() {
  simulationSpace.resize(xMax - xMin);
  for(int column = xMin; column < xMax; column++) {
    for(int row = yMin; row < yMax; row++) {
      simulationSpace.at(column).push_back(std::make_shared<Cell>(column, row));
    }
  }
}
