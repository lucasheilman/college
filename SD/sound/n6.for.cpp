#include <iostream>
using namespace std;

int main()
{
  int x = 1;
  int y;
  int z = 0;
  int a = 1;
  for (;x < 11;x++)
    {
      y = z + a;
      cout << y << endl;
      a = z;
      z = y;
    }
  return 0;
}