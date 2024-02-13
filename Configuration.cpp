//
// Created by User on 2024. 02. 11..
//

#include <stdexcept>
#include "Configuration.h"
void Configuration::setEmitterPoint(std::shared_ptr<Cell> point) {
  this->emitterPoint = std::move(point);
}
void Configuration::setStartingPoint(std::shared_ptr<Cell> point) {
  this->startingPoint = std::move(point);
}
void Configuration::addTargetPoint(std::shared_ptr<Cell> point) {
  this->targetPoints.push_back(std::move(point));
}
void Configuration::setCellSize(double size) {
  if(size < 0)throw std::invalid_argument("cell size can't be negative");
  this->cellSize = size;
}
void Configuration::setPictureHeight(int size) {
  if(size < 0)throw std::invalid_argument("picture height can't be negative");
  this->pictureHeight = size;
}
void Configuration::setPictureWidth(int size) {
  if(size < 0)throw std::invalid_argument("picture width can't be negative");
  this->pictureWidth = size;
}
bool Configuration::isInPicture(double x, double y) {
  return x >= startingPoint->getX() && x <= startingPoint->getX() + pictureWidth &&
  y <= startingPoint->getY() && y >= startingPoint->getY() - pictureHeight;
}
