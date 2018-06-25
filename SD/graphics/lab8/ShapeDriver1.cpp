#include <iostream>
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
 
int main()
{
  Point2 p;
  p.x = 10;
  p.y = 10;
  Rectangle d2(p,1,1);
  Rectangle d3(cin);
  d2.display(); cout << endl;
  d3.display(); cout << endl;
  Point2 p1;
  p1.x = 20;
  p1.y = 20;
  Circle d4(p1,11);
  Circle d5(cin);
  d4.display(); cout << endl;
  d5.display(); cout << endl;
}

