//
// Created by User on 2024. 02. 11..
//

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
  this->cellSize = size;
}
void Configuration::setPictureHeight(int size) {
  this->pictureHeight = size;
}
void Configuration::setPictureWidth(int size) {
  this->pictureWidth = size;
}
bool Configuration::isInPicture(double x, double y) {
  return x >= startingPoint->getX() && x <= startingPoint->getX() + pictureWidth &&
  y <= startingPoint->getY() && y >= startingPoint->getY() - pictureHeight;
}
