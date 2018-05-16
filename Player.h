#pragma once
#include "Board.h"

//Player in the game
class Player{
  protected:
    char myChar;
  public:
    void setChar(char c){
      myChar = c;
    }
    char getChar()const{
      return myChar;
    }
    virtual const Coordinate play(const Board& board){
      return {0,0};
    }
    virtual const string name() const{
      return "default";
    }
};
