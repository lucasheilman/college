#include<iostream>
using namespace std;

struct Pixel{
  int red;
  int green;
  int blue;
};
  
int main()
{
  Pixel p1;
  p1.red = p1.green = p1.blue = 17;
  cout << "p1.green " << (int)p1.green << endl;
  return 0;
}
