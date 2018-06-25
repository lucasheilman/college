#include <iostream>
using namespace std;

int main()
{
  int x = 1;
  int y = 1;
  cout << 1 << endl;
  for (;x < 10;x=x+1)
    {
      y = x*(y);
      cout << y << endl;
    }
  return 0;
}
