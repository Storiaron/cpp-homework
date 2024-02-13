//
// Created by User on 2024. 02. 11..
//

#ifndef CPP_HOMEWORK__SIMULATOR_H_
#define CPP_HOMEWORK__SIMULATOR_H_

#include <vector>
#include "Cell.h"
#include "Configuration.h"
#include "FileWriter.h"
class Simulator {
 public:
  void run(double cellSize, int emitterPointX, int emitterPointY, int pictureStartingPointX,
           int pictureStartingPointY, int pictureWidth, int pictureHeight,
           std::vector<std::pair<int, int>> targetPointCoordinates, const std::string& filePath);
 private:
  Configuration configuration;
  FileWriter fileWriter;
  void setupConfiguration(double cellSize, int emitterPointX, int emitterPointY, int pictureStartingPointX,
                          int pictureStartingPointY, int pictureWidth, int pictureHeight,
                          std::vector<std::pair<int, int>> targetPointCoordinates);
  void calculateAndLogResult(const std::shared_ptr<Cell>& targetPoint, const std::string& filePath);
  void calculateDirectionVector(double& directionVectorX, double& directionVectorY, const std::shared_ptr<Cell>& targetPoint);
  void determineDirectionVectorSigns(double& directionVectorX,
                                     double& directionVectorY, const std::shared_ptr<Cell>& targetPoint);
};

#endif //CPP_HOMEWORK__SIMULATOR_H_
