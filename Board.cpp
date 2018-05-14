#include "Board.h"

//Constructor and Destructor
Board::Board(int newSize){
  size = newSize;
  arr = new Slot*[size];
  for(int i=0; i<size; i++){
    arr[i] = new Slot[size];
  }
}
Board::Board(const Board& other){
  size = other.size;
  arr = new Slot*[size];
  for(int i = 0 ; i < size ; i++){
      arr[i] = new Slot[size];
      for (int j = 0; j < size; j++) {
        arr[i][j].insert(other.arr[i][j].getChar());
      }
  }
}
Board::~Board(){
  for (int i = 0; i < size; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}
//operator overloads
ostream& operator<< (ostream& o, Board const& b){
  for(int i=0;i<b.size;i++){
    for(int j=0;j<b.size;j++){
      o << b.arr[i][j];
    }
    o << "\n";
  }
  return o;
}
Slot& Board::operator[](const Coordinate& c){
  if(c.getX()>=size || c.getY()>=size || c.getX()<0 || c.getY()<0)
    throw IllegalCoordinateException(c);
  return arr[c.getX()][c.getY()];
}
Board& Board::operator=(char c){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      arr[i][j].insert(c);
    }
  }
  return *this;
}
Board& Board::operator=(const Board& other){
    this->~Board();
    size = other.size;
    arr = new Slot*[size];
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = new Slot[size];
        for(int j = 0; j < size; j++)
        {
            arr[i][j] = other.arr[i][j];
        }
    }
    return *this;
}
