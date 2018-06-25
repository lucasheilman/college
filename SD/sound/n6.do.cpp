#include <iostream>
using namespace std;

int main()
{
  int x = 1;
  int y;
  int z = 0;
  int a = 1;
  do
    {
      y = z + a;
      cout << y << endl;
      a = z;
      z = y;
      x++;
    }while (x < 11);
  return 0;
}
