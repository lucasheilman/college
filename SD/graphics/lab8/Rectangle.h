#ifndef _Rectangle_H_
#define _Rectangle_H_
#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape{
 public:
  int width;
  int height;
  Rectangle();
  Rectangle(Point2, int, int);
  Rectangle(istream &);
  ~Rectangle();
  void display();
  void draw();
};

#endif /* _Rectangle_H_ */

