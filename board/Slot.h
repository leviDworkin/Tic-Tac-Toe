#pragma once
#include<iostream>
using namespace std;
#include "IllegalCharException.h"

class Slot{
  private:
    char c;
  public:
    Slot(char newC):c(newC){}
    Slot(const Slot& other):c(other.c){}
    Slot():c('.'){}

    friend ostream& operator<< (std::ostream& o, Slot const& slot){
      o << slot.c;
      return o;
    }

    Slot& insert(char newC){
      if(newC!='X' && newC!='O' && newC!='.')
        throw IllegalCharException(newC);
      c = newC;
      return *this;
    }

    Slot& operator=(char newC){
      if(newC!='X' && newC!='O' && newC!='.')
        throw IllegalCharException(newC);
      c = newC;
      return *this;
    }

    Slot& operator=(const Slot& other){
      c = other.c;
      return *this;
    }

    bool operator==(char other)const{
      if(c==other)
        return true;
      return false;
    }
    bool operator!=(char other)const{
      if(c!=other)
        return true;
      return false;
    }
    char getChar()const{
      return c;
    }
};
