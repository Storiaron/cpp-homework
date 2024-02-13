//
// Created by User on 2024. 02. 13..
//

#ifndef CPP_HOMEWORK__APPLICATION_H_
#define CPP_HOMEWORK__APPLICATION_H_

#include <string>
class Application {
 public:
  void run();
 private:
  int getUserInputInt(std::string userPrompt);
  int getUserInputNonNegativeInt(std::string userPrompt);
  double getUserInputNonNegativeDouble(std::string userPrompt);
  bool getUserInputBoolean(std::string userPrompt);
};

#endif //CPP_HOMEWORK__APPLICATION_H_
