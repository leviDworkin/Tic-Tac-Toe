#pragma once
#include "Player.h"

class Champion: public Player{
  private:
    char playingAs;
  public:
    Champion(char c): playingAs(c) {}
    const string name() const override { return "Levi"; }
  	const Coordinate play(const Board& board) override{
      return {0,0};
    }
    char getChar()const{
      return playingAs;
    }
};
