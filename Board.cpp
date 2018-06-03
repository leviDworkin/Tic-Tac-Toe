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
    string line;
    is >> line;
    if(is.fail()){
      cout << "Error opening file" << endl;
      exit(1);
    }
    uint row=0;
    Board tmp((int)line.size());
    while (row<tmp.size()) {
      for (uint j = 0; j < tmp.size(); j++) {
        tmp[{row,j}] = line[j];
      }
      is>>line;
      row++;
    }
    b = tmp;
    return is;
}
string Board::draw(int pixels){
  const int dimx = pixels, dimy = pixels;
  int bound = pixels/_size;
  ofstream imageFile("image2.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;

  RGB* image = new RGB[dimx*dimy];
	size_t counterx=0;
  size_t countery=0;
	for (size_t i = 0; i <_size ; ++i) {
		for (size_t j = 0; j <_size ; ++j) {
			if (arr[i][j] == 'X'){
				for (int k = counterx*bound; k <(counterx+1)*bound ; ++k) {
          for (int l = countery*bound; l <(countery+1)*bound ; ++l) {
              image[dimx*l+k].red = (255);
          }
				}
        counterx++;
			}else if (arr[i][j] == 'O'){
        for (int k = counterx*bound; k <(counterx+1)*bound ; ++k) {
            for (int l = countery*bound; l <(countery+1)*bound ; ++l) {
                image[dimx*l+k].green = (255);
            }
        }
        counterx++;
			}else{
        for (int k = counterx*bound; k <(counterx+1)*bound ; ++k) {
            for (int l = countery*bound; l <(countery+1)*bound ; ++l) {
                image[dimx*l+k].blue = 0;
            }
        }
        counterx++;
      }
		}
   counterx=0;
   countery++;
	}

  ///image processing
  imageFile.write(reinterpret_cast<char*>(image), 3*dimx*dimy);
  imageFile.close();
  delete[] image;
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
