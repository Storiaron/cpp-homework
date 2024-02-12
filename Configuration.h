//
// Created by User on 2024. 02. 11..
//

#ifndef CPP_HOMEWORK__CONFIGURATION_H_
#define CPP_HOMEWORK__CONFIGURATION_H_

#include <vector>
#include <memory>
#include "Cell.h"
class Configuration{
 public:
  void setEmitterPoint(std::shared_ptr<Cell> point);
  void setStartingPoint(std::shared_ptr<Cell> point);
  void addTargetPoint(std::shared_ptr<Cell> point);
  void setCellSize(double size);
  void setPictureHeight(int size);
  void setPictureWidth(int size);
  bool isInPicture(double x, double y);
  const std::vector<std::shared_ptr<Cell>>& getTargetPoints() { return targetPoints;}
  const std::shared_ptr<Cell>& getEmitterPoint() { return emitterPoint;}
  double getCellSize() { return cellSize;}
 private:
  double cellSize;
  int pictureWidth;
  int pictureHeight;
  std::vector<std::vector<std::shared_ptr<Cell>>> simulationSpace;
  std::shared_ptr<Cell> emitterPoint;
  std::vector<std::shared_ptr<Cell>> targetPoints;
  std::shared_ptr<Cell> startingPoint;
};
#endif //CPP_HOMEWORK__CONFIGURATION_H_
