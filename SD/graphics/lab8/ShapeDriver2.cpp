#include <iostream>
using namespace std;
#include <fstream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
 
int main()
{
  ifstream g("shapes.txt");
  int numshapes;
  g >> numshapes;
  Shape *myShapeArray[numshapes];
  for(int i = 0; i < numshapes; i++){
    char shape[64];
    g >> shape;
    if(shape[0] == 'R'){
      myShapeArray[i] = new Rectangle(g);
    }
    if(shape[0] == 'C'){
      myShapeArray[i] = new Circle(g);
    }
  }
  for (int i = 0;i<numshapes;i++){
    myShapeArray[i]->display();
  }
  g.close();
}

