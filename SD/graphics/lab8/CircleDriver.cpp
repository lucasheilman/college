#include<iostream>
using namespace std;
#include"Shape.h"
#include "Circle.h"
 
int main()
{
  Circle d1;
  Point2 p;
  p.x = 10;
  p.y = 10;
  Circle d2(p,10);
  Circle d3(cin);
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
}

