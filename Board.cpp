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
istream& operator>> (istream& is, Board& b){
    string filename,line;
    is >> filename;
    ifstream infile;
    infile.open(filename);
    if(infile.fail()){
      cout << "Error opening file" << endl;
      exit(1);
    }
    uint row=0;
    infile >> line;
    Board tmp((int)line.size());
    while (row<tmp.size()) {
      if(row!=0)
        infile >> line;
      for (uint j = 0; j < tmp.size(); j++) {
        tmp[{row,j}] = line[j];
      }
      row++;
    }
    b = tmp;
    infile.close();
    return is;
}
string Board::draw(int pixels){
  const int dimx = pixels, dimy = pixels;
  ofstream imageFile("image2.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
  RGB image[dimx*dimy];
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
      image[dimx*j+i].red = (i % 256);
      image[dimx*j+i].green = (j % 256);
      image[dimx*j+i].blue = ( (i*i+j*j) % 256);
    }
  }
  image[0].red = 255;
  image[0].blue = 0;
  image[0].green = 0;
  ///
  ///image processing
  ///
  imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
  imageFile.close();
  return "image2.ppm";
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
