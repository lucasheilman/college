#include <iostream>
using namespace std;

class Square {
    int side;
  public:
    Square (int);
    int area (void) {return (side*side);}
};

Square::Square(int a){
  side = a;
}

int main () {
  Square square(3);
  Square squareb = 3;
  Square squarec {3};
  Square squared = {3};
  cout << "square area: " << square.area() << endl;
  cout << "squareb area: " << squareb.area() << endl;
  cout << "squarec area: " << squarec.area() << endl;
  cout << "squared area: " << squared.area() << endl;
  return 0;
}
