#pragma once
#include "Board.h"
#include "Player.h"

class TicTacToe{
  public:
    TicTacToe(uint size): gameBoard(size) {}
    TicTacToe& play(Player& x,Player& o){
      gameBoard = '.';
      int turn =0;
      for(uint i=0; i<gameBoard.size()*gameBoard.size(); i++ ){
          if(turn==0){
            try{
              if( isIllegal(gameBoard[x.play(gameBoard)]) ){
                oWins(&o);
                break;
              }
            }catch(...){
              oWins(&o);
              break;
            }
            gameBoard[x.play(gameBoard)]='X';
            turn=1;
            if(isWinner('X')){
              xWins(&x);
              break;
            }
          }else{
            try{
              if( isIllegal(gameBoard[o.play(gameBoard)]) ){
                xWins(&x);
                break;
              }
            }catch(...){
              xWins(&x);
              break;
            }
            gameBoard[o.play(gameBoard)]='O';
            turn=0;
            if(isWinner('O')){
              oWins(&o);
              break;
            }
          }
      }
      if(isTie())
        oWins(&o);
      return *this;
    }
    Board board()const{
      return gameBoard;
    }
    Player& winner()const{
      return *p;
    }

  private:
    Board gameBoard;
    char won;
    Player* p;

    void oWins(Player* o){
      p = o;
      p->setChar('O');
    }
    void xWins(Player* x){
      p = x;
      p->setChar('X');
    }
    bool horizontalWin(char c){
      for (uint i = 0; i < gameBoard.size(); i++) {
        if(checkHorizontal(i,c)){
          return true;
        }
      }
      return false;
    }
    bool verticalWin(char c){
      for (uint i = 0; i < gameBoard.size(); i++) {
        if(checkVertical(i,c)){
          return true;
        }
      }
      return false;
    }
    bool checkHorizontal(uint i, char c){
      for (uint j = 0; j < gameBoard.size(); j++) {
        if(gameBoard[{i,j}]!=c){
          return false;
        }
      }
      return true;
    }
    bool checkVertical(uint i, char c){
      for (uint j = 0; j < gameBoard.size(); j++) {
        if(gameBoard[{j,i}]!=c){
          return false;
        }
      }
      return true;
    }
    bool isWinner(char c){
      if(horizontalWin(c) || verticalWin(c) /*|| diagonalWin(c)*/)
        return true;
      return false;
    }
    bool isIllegal(const Slot& s){
      if (s=='X' || s=='O') {
        return true;
      }
      return false;
    }
    bool isTie(){
      if(!isWinner('O') && !isWinner('X'))
        return true;
      return false;  
    }
    // bool diagonalWin(char c){
    //   for (uint i=0 ,j = 0; i < gameBoard.size(); i++, j++) {
    //     if(gameBoard[{i,j}] != c)
    //       return false;
    //   }
    //   for (uint i=gameBoard.size()-1 ,j = gameBoard.size()-1; i >= 0; i--, j--) {
    //     if(gameBoard[{i,j}] != c)
    //       return false;
    //   }
    //   return true;
    // }
};
