#include <iostream>
using namespace std;
#include "Shape.h"
 
int main()
{
  Shape d1;
  Point2 p;
  p.x = 10;
  p.y = 10;
  Shape d2(p);
  Shape d3(cin);
  cout << "After constructors:" << endl;
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]

  Color c;
  c.red = 200;
  c.green = 200;
  c.blue = 200;
  d1.setColor(c);
  d1.setPosition(100,100);
 
  cout << "After state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /Ingmar Bergman]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
}

