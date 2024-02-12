//
// Created by User on 2024. 02. 11..
//

#ifndef CPP_HOMEWORK__FILEWRITER_H_
#define CPP_HOMEWORK__FILEWRITER_H_

#include <string>
#include <set>
#include <unordered_set>
class FileWriter {
 public:
  void logResult(const std::string& result,const std::unordered_set<std::string>& visitedCells, const std::string& filePath);
};

#endif //CPP_HOMEWORK__FILEWRITER_H_
