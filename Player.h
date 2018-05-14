#pragma once
#include "Board.h"

class Player{
  virtual const Coordinate play(const Board& board);
  virtual const string name() const;
};