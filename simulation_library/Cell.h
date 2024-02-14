//
// Created by User on 2024. 02. 11..
//

#ifndef CPP_HOMEWORK__CELL_H_
#define CPP_HOMEWORK__CELL_H_

class Cell {
 public:
  Cell(int x, int y) : x(x), y(y) {}
  Cell(const Cell& other) : x(other.x), y(other.y) {}
  const int& getX()const { return x;}
  const int& getY()const { return y;}
  bool operator== (const Cell& other) {
    return other.getX() == x && other.getY() == y;
  }
 private:
  const int x;
  const int y;
};

#endif //CPP_HOMEWORK__CELL_H_
