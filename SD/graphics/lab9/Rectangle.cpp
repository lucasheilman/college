#include <iostream>
using namespace std;
#include "Rectangle.h"
#include "Shape.h"
#include <GL/glut.h>
#include <math.h>

Rectangle::Rectangle(): Shape::Shape(){
  width = 100;
  height = 100;
}

Rectangle::Rectangle(Point2 p, int w, int h): Shape::Shape(p){
  width = w;
  height = h;
}

Rectangle::Rectangle(istream &is): Shape::Shape(is){
  int widthin;
  int heightin;
  //cout << "what is width";
  is >> widthin;
  //cout << "what is height";
  is >> heightin;
  width = widthin;
  height = heightin;
}

Rectangle::~Rectangle(){}

void Rectangle::draw(){
  sendGLColor();
  double x0 = min(position.x, position.x + width);
  double x1 = max(position.x, position.x + width);
  double y0 = min(position.y, position.y + height);
  double y1 = max(position.y, position.y + height);
  glBegin(GL_QUADS);
    glVertex2d(x0, y0);
    glVertex2d(x1, y0);
    glVertex2d(x1, y1);
    glVertex2d(x0, y1);
  glEnd();
}

void Rectangle::display(){
  cout << "Rectangle " << color.red << " " << color.green << " " << color.blue << " " << position.x << " " << position.y << " " << width << " " << height;
}

int Rectangle::distance(int x, int y, Point2 p){
  double dx = x-p.x;
  double dy = y-p.y;
  return sqrt(dx*dx + dy*dy);
}

void Rectangle::update(int x, int y){
  width = x-position.x;
  height = y-position.y;
}

bool Rectangle::containsPoint(int x,int y){
  double x0 = min(position.x, position.x + width);
  double x1 = max(position.x, position.x + width);
  double y0 = min(position.y, position.y + height);
  double y1 = max(position.y, position.y + height);
  if(x > x0 && x < x1 && y > y0 && y < y1){
    return true;
  }
  else{
    return false;
  }
}
