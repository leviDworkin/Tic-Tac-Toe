#pragma once
#include "Board.h"
//Player in the game
class Player{
  virtual const Coordinate play(const Board& board);
  virtual const string name() const;
};
