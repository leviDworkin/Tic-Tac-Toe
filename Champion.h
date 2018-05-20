#pragma once
#include "Player.h"

class Champion: public Player{
  public:
    const string name() const override { return "Levi"; }
  	const Coordinate play(const Board& board) override{
      for (uint i = 0; i < board.size(); i++) {
        for (uint j = 0; j < board.size(); j++) {
          Coordinate c{i,j};
          if(board[c] != '.')
            return c;
        }
      }
      return {board.size()-1,board.size()-1};
    }
};
