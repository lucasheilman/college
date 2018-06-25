// example: one class, two objects
#include <iostream>
using namespace std;
class CTriangle {
 int x, y;
 public:
 void set_values (int,int);
  int area () {return (((x*y)/2));}
};
void CTriangle::set_values (int a, int b) {
 x = a;
 y = b;
}
int main () {
 CTriangle tri, trib;
 tri.set_values (3,4);
 trib.set_values (5,6);
 cout << "tri area: " << tri.area() << endl;
 cout << "trib area: " << trib.area() << endl;
 return 0;
} 
