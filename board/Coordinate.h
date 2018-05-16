#pragma once
#include <iostream>
using namespace std;

class Coordinate{
  private:
    uint x,y;
  public:
    Coordinate(uint newX, uint newY): x(newX),y(newY) {}
    Coordinate(const Coordinate& other): x(other.x), y(other.y) {}
    uint getX()const{
      return x;
    }
    uint getY()const{
      return y;
    }
};
