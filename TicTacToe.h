#pragma once
#include "Board.h"
#include "Player.h"

class TicTacToe{
  private:
    Board gameBoard;
    char won;
    Player p;
  public:
    TicTacToe(int size): gameBoard(size) {}
    TicTacToe& play(const Player& x,const Player& o){
      gameBoard = '.';
      int turn =0;
      while( check() ){
          if(turn==0){
            gameBoard[x.play(gameBoard)]='X';
            turn=1;
          }else{
            gameBoard[o.play(gameBoard)]='O';
            turn=0;
          }
      }
      return *this;
    }
    Board& board(){
      return gameBoard;
    }
    Player& winner();//returns the winner if there is a tie the winner is the o player
    bool check(){
      if(verticalWin() || horizontalWin() || digonalWin()){

          return false;
      }
      return true;
    }
    bool horizontalWin(){
      int countx=0 , counto=0;
      for (size_t i = 0; i < gameBoard.size(); i++) {
        for (size_t j = 0; j < gameBoard.size(); j++) {
            if(gameBoard[{i,j}]=='X'){
              countx++; counto=0;
            }else if(gameBoard[{i,j}]=='O'){
              counto++; countx=0;
            }else{
              countx=0; counto=0;
            }
        }
        if(countx==gameBoard.size()){
          won = 'X';
          return true;
        }
        if(counto==gameBoard.size()){
          won = 'O';
          return true;
        }
        countx=0; counto=0;
      }
      return false;
    }
    bool verticalWin(){
      for (size_t i = 0; i < gameBoard.size(); i++) {
        for (size_t j = 0; j < gameBoard.size(); j++){
          if()
        }
      }
    }
};
