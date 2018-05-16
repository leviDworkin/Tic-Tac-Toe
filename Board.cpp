#include "Board.h"

//Constructor and Destructor
Board::Board(int new_size){
  _size = new_size;
  arr = new Slot*[_size];
  for(int i=0; i<_size; i++){
    arr[i] = new Slot[_size];
  }
}
Board::Board(const Board& other){
  _size = other._size;
  arr = new Slot*[_size];
  for(int i = 0 ; i < _size ; i++){
      arr[i] = new Slot[_size];
      for (int j = 0; j < _size; j++) {
        arr[i][j].insert(other.arr[i][j].getChar());
      }
  }
}
Board::~Board(){
  for (int i = 0; i < _size; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}
//operator overloads
ostream& operator<< (ostream& o, Board const& b){
  for(int i=0;i<b._size;i++){
    for(int j=0;j<b._size;j++){
      o << b.arr[i][j];
    }
    o << "\n";
  }
  return o;
}
Slot& Board::operator[](const Coordinate& c)const{
  if(c.getX()>=_size || c.getY()>=_size)
    throw IllegalCoordinateException(c);
  return arr[c.getX()][c.getY()];
}
Board& Board::operator=(char c){
  for(int i=0;i<_size;i++){
    for(int j=0;j<_size;j++){
      arr[i][j].insert(c);
    }
  }
  return *this;
}
Board& Board::operator=(const Board& other){
    this->~Board();
    _size = other._size;
    arr = new Slot*[_size];
    for(int i = 0 ; i < _size ; i++)
    {
        arr[i] = new Slot[_size];
        for(int j = 0; j < _size; j++)
        {
            arr[i][j] = other.arr[i][j];
        }
    }
    return *this;
}
