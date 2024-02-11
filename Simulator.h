//
// Created by User on 2024. 02. 11..
//

#ifndef CPP_HOMEWORK__SIMULATOR_H_
#define CPP_HOMEWORK__SIMULATOR_H_

#include <vector>
#include "Cell.h"
#include "Configuration.h"
class Simulator {
 public:
  void run();
 private:
  Configuration configuration;
  void setupConfiguration();
  void getCellSize();
  void createEmitterPoint();
  void createTargetPoints();
  void createStartingPoint();
  void createPicture();
};

#endif //CPP_HOMEWORK__SIMULATOR_H_
