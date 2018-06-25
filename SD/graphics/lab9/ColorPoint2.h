#include <iostream>
using namespace std;

struct Color{
  int red;
  int green;
  int blue;
  void display(){
    cout << red << " " << green << " " << blue <<  endl;
  }
};


struct Point2{
  int x;
  int y;
  void display(){
    cout << x << " " << y << endl;
  }
};
