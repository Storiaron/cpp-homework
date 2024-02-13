//
// Created by User on 2024. 02. 12..
//

#ifndef CPP_HOMEWORK_TEST_CONFIGURATIONTESTER_H_
#define CPP_HOMEWORK_TEST_CONFIGURATIONTESTER_H_

#include "../Configuration.h"
class ConfigurationTester {
 public:
  void run();
 private:
  bool invalidInputIntTest();
  bool invalidInputDoubleTest();
  bool invalidInputSmallTest();
  bool isInPictureTest(int startingPointX, int startingPointY,
                       int width, int height, double pointX, double pointY);
};

#endif //CPP_HOMEWORK_TEST_CONFIGURATIONTESTER_H_
