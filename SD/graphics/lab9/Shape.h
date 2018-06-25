#ifndef _Shape_H_
#define _Shape_H_
#include "ColorPoint2.h"
#include <iostream>
using namespace std;

class Shape{
 public:
  Color color;
  Point2 position;
  Shape();
  Shape(Point2);
  Shape(istream &);
  ~Shape();
  Color getColor();
  Point2 getPosition();
  void setColor(Color);
  void setPosition(int,int);
  void display();
  void sendGLColor();
  virtual void draw() = 0;
  virtual void update(int,int) = 0;
  virtual bool containsPoint(int,int) = 0;
};

#endif /* _Shape_H_ */

