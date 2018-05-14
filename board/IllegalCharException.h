#pragma once
#include <iostream>
using namespace std;

class IllegalCharException{
  private:
    char c;
  public:
    IllegalCharException(char cVal) : c(cVal) {}
    char theChar() const{
      return c;
    }
};
