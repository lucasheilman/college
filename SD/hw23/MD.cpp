#include<iostream>
using namespace std;

class Walker {
protected:
  int left, right;
public:
  Walker(int j=2) : left(j), right(j) {}
  void animate() { cout << "walking!" << endl; }
};
 
class Merchant : public Walker {
  double capital;
public:
  Merchant() : Walker(1) { capital = 100; left += 1; }
  Merchant(double c) { capital = c + 20; }
  void animate() { cout << "trading." << endl; }
};
 
int main()
{
  Merchant antonio, bassanio(200);
  Walker *w = &antonio;
  w->animate();
  bassanio.animate();
}
