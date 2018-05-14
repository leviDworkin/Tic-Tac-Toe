#pragma once
#include<string>
#include<iostream>
using namespace std;
#include "Coordinate.h"

class IllegalCoordinateException{
  private:
    Coordinate c;
  public:
    IllegalCoordinateException(Coordinate newC) : c(newC){}
    string theCoordinate() const{
      string ans = to_string(c.getX())+","+to_string(c.getY());
      return ans;
    }
};
