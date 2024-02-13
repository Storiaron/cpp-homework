//
// Created by User on 2024. 02. 11..
//

#include <stdexcept>
#include "Configuration.h"
void Configuration::setEmitterPoint(std::shared_ptr<Cell> point) {
  this->emitterPoint = std::move(point);
}
void Configuration::setPictureStartingPoint(std::shared_ptr<Cell> point) {
  this->pictureStartingPoint = std::move(point);
}
void Configuration::setTargetPoints(std::vector<std::shared_ptr<Cell>> points) {
  this->targetPoints = points;
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
  return x >= pictureStartingPoint->getX() && x <= pictureStartingPoint->getX() + pictureWidth &&
  y <= pictureStartingPoint->getY() && y >= pictureStartingPoint->getY() - pictureHeight;
}
