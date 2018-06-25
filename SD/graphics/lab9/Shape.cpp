#include <iostream>
using namespace std;
#include "Shape.h"
#include <GL/glut.h>

Shape::Shape(){
  color.red = 0;
  color.green = 0;
  color.blue = 255;
  position.x = 0;
  position.y = 0;
}

Shape::Shape(Point2 p){
  color.red = 0;
  color.green = 0;
  color.blue = 255;
  position.x = 200;
  position.y = 200;
}

Shape::Shape(istream &is){
  int redin;
  int greenin;
  int bluein;
  int xin;
  int yin;
  //cout << "what is red";
  is >> redin;
  //cout << "what is green";
  is >> greenin;
  //cout << "what is blue";
  is >> bluein;
  //cout << "what is x";
  is >> xin;
  // cout << "what is y";
  is >> yin;
  color.red = redin;
  color.green = greenin;
  color.blue = bluein;
  position.x = xin;
  position.y = yin;
}

Shape::~Shape(){
}

Color Shape::getColor(){
  return color;
}

Point2 Shape::getPosition(){
  return position;
}

void Shape::setColor(Color c){
  color.red = c.red;
  color.green = c.green;
  color.blue = c.blue;
}

void Shape::setPosition(int xs, int ys){
  position.x = xs;
  position.y = ys;
}

void Shape::sendGLColor(){
  glColor3f(color.red/255.,color.green/255.,color.blue/255.);
}

void Shape::display(){
  cout << " " << color.red  << " " << color.green << " " << color.blue << " " << position.x << " " << position.y << endl;
}

