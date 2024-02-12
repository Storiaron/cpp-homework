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
  void run();
 private:
  Configuration configuration;
  FileWriter fileWriter;
  void setupConfiguration();
  void getCellSize();
  void createEmitterPoint();
  void createTargetPoints();
  void createStartingPoint();
  void createPicture();
  void calculateAndLogResult(const std::shared_ptr<Cell>& targetPoint);
  void calculateDirectionVector(double& directionVectorX, double& directionVectorY, const std::shared_ptr<Cell>& targetPoint);
  void determineDirectionVectorSigns(double& directionVectorX,
                                     double& directionVectorY, const std::shared_ptr<Cell>& targetPoint);
};

#endif //CPP_HOMEWORK__SIMULATOR_H_
