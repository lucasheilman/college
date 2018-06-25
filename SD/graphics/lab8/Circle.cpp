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
  cout << "what is radius";
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

