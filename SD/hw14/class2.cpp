// example: class constructor
#include <iostream>
using namespace std;
class CTriangle {
 int width, height;
 public:
 CTriangle (int,int);
  int area () {return (((width*height)/2));}
};
CTriangle::CTriangle (int a, int b) {
 width = a;
 height = b;
}
int main () {
 CTriangle tri (3,4);
 CTriangle trib (5,6);
 cout << "tri area: " << tri.area() << endl;
 cout << "trib area: " << trib.area() << endl;
 return 0;
} 
