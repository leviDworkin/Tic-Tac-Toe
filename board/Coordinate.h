#pragma once
#include <iostream>
using namespace std;

class Coordinate{
  private:
    int x,y;
  public:
    Coordinate(int newX, int newY): x(newX),y(newY) {}
    Coordinate(const Coordinate& other): x(other.x), y(other.y) {}
    int getX()const{
      return x;
    }
    int getY()const{
      return y;
    }
};
