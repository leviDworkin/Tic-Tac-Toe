#pragma once
#include <iostream>
using namespace std;
#include"board/IllegalCoordinateException.h"
#include "board/IllegalCharException.h"
#include "board/Slot.h"
#include "board/Coordinate.h"
#include<string>

class Board{
  private:
    Slot** arr;
    int size;
  public:
    //Constructor and Destructor
    Board(int newSize);
    Board(const Board& other);
    ~Board();
    //Methods
    friend std::ostream& operator<< (std::ostream& o, Board const& b);
    Slot& operator[](const Coordinate& c);
    Board& operator=(char c);
    Board& operator=(const Board& other);
    const int getSize()const{
      return size;
    }
};
