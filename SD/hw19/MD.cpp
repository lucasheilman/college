#include<iostream>
using namespace std;
 
class Position {
public:
  double x, y;

  Position(float *k) { x = *k;  y = *k+1; }
  void move_left(int t) { x -= t; }
  void zoom() { cout << x << " " << y;}
};
 
int main()
{
  float d[2] = {4, 6};
  Position a(d), b(d+1);
  a.move_left(3);
  a.zoom(); cout << endl;
}
