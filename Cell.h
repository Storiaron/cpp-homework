//
// Created by User on 2024. 02. 11..
//

#ifndef CPP_HOMEWORK__CELL_H_
#define CPP_HOMEWORK__CELL_H_

class Cell {
 public:
  Cell(int x, int y) : x(x), y(y) {}
  const int& getX()const { return x;}
  const int& getY()const { return y;}
  bool operator<(const Cell &other) const {
    if (x < other.x)
      return true;
    if (other.x < x)
      return false;
    return y < other.y;
  }
  bool operator>(const Cell &other) const {
    return other < *this;
  }
  bool operator<=(const Cell &other) const {
    return !(other < *this);
  }
  bool operator>=(const Cell &other) const {
    return !(*this < other);
  }
 private:
  const int x;
  const int y;
};

#endif //CPP_HOMEWORK__CELL_H_
