#ifndef _Circle_H_
#define _Circle_H_
#include "Shape.h"
#include <iostream>
using namespace std;

class Circle : public Shape{
 public:
  int radius;
  Circle();
  Circle(Point2, int);
  Circle(istream &);
  ~Circle();
  void display();
  void draw();
};

#endif /* _Circle_H_ */

