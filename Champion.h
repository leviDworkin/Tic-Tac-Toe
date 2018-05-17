#pragma once
#include "Player.h"

class Champion: public Player{
  public:
    const string name() const override { return "Levi"; }
  	const Coordinate play(const Board& board) override{
      return {0,0};
    }
    // char getChar()const{
    //   return this->myChar;
    // }
};
