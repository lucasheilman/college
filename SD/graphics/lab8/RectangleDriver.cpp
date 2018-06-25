#include<iostream>
using namespace std;
#include"Shape.h"
#include "Rectangle.h"
 
int main()
{
  Rectangle d1;
  Point2 p;
  p.x = 10;
  p.y = 10;
  Rectangle d2(p,10,10);
  Rectangle d3(cin);
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
}

