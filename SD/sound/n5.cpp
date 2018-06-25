#include <iostream>
using namespace std;

int main()
{
  int x = 1;
  int y = 1;
  cout << 1 << endl;
  while (x < 10)
    {
      y = x*(y);
      cout << y << endl;
      x = x+1;
    }
  return 0;
}
