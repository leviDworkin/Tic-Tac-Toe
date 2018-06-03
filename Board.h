#pragma once
#include <iostream>
using namespace std;
#include"board/IllegalCoordinateException.h"
#include "board/IllegalCharException.h"
#include "board/Slot.h"
#include "board/Coordinate.h"
#include <string>
#include <fstream>
#include <sys/stat.h>

class Board{
  private:
    Slot** arr;
    int _size;
  public:
    //Constructor and Destructor
    Board(int newSize);
    Board(const Board& other);
    Board():arr(nullptr),_size(0){}
    ~Board();
    //Methods
    friend std::ostream& operator<< (std::ostream& o, Board const& b);
    friend std::istream& operator>> (std::istream& is, Board& b);
    Slot& operator[](const Coordinate& c)const;
    Board& operator=(char c);
    Board& operator=(const Board& other);
    const uint size()const{
      return (uint)_size;
    }
    string draw(int pixels);
};

struct RGB {
  uint8_t red, green, blue;
  public:
    RGB() {}
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};
