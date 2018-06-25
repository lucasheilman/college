#include <iostream>
using namespace std;
#include "Circle.h"
#include "Shape.h"
#include <GL/glut.h>
#include <math.h>

Circle::Circle(): Shape::Shape(){
  radius = 0;
}

Circle::Circle(Point2 p, int r): Shape::Shape(p){
  radius = r;
}

Circle::Circle(istream &is): Shape::Shape(is){
  int radiusin;
  //cout << "what is radius";
  is >> radiusin;
  radius = radiusin;
}

Circle::~Circle(){}

void Circle::draw(){
  sendGLColor();
  const int NUM_DIVS = 50;
  glBegin(GL_TRIANGLE_FAN);
    glVertex2d(position.x, position.y);
    for ( int i = 0; i < NUM_DIVS; ++i )
      glVertex2d(position.x + radius*cos(i*2*M_PI/(NUM_DIVS-1)),
                 position.y + radius*sin(i*2*M_PI/(NUM_DIVS-1)));
  glEnd();
}

void Circle::display(){
  cout << "Circle " << color.red << " " << color.green << " " << color.blue << " " << position.x << " " << position.y << " " << radius;
}

int Circle::distance(int x, int y, Point2 p){
  double dx = x-p.x;
  double dy = y-p.y;
  return sqrt(dx*dx + dy*dy);
}

void Circle::update(int x, int y){
  radius = distance(x,y,position);
}

bool Circle::containsPoint(int x,int y){
  float isit = distance(x,y,position);
  if(isit < radius){
    return true;
  }
  else{
    return false;
  }
}
