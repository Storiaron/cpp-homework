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
  void setEmitterPoint(std::unique_ptr<Cell> point);
  void setStartingPoint(std::unique_ptr<Cell> point);
  void addTargetPoint(std::unique_ptr<Cell> point);
  void setCellSize(int size);
  void setPictureHeight(int size);
  void setPictureWidth(int size);
  void setupSimulationSpace();
  int getXMax() { return xMax;}
  int getYMax() {return yMax;}
  int getXMin() { return xMin;}
  int getYMin() {return yMin;}
 private:
  int cellSize;
  int pictureWidth;
  int pictureHeight;
  int xMax{0};
  int xMin{0};
  int yMax{0};
  int yMin{0};
  std::vector<std::vector<std::unique_ptr<Cell>>> simulationSpace;
  std::unique_ptr<Cell> emitterPoint;
  std::vector<std::unique_ptr<Cell>> targetPoints;
  std::unique_ptr<Cell> startingPoint;
  void setXMinMax(int candidateX);
  void setYMinMax(int candidateY);
};
#endif //CPP_HOMEWORK__CONFIGURATION_H_
