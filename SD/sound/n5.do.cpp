#include <iostream>
using namespace std;

int main()
{
  int x = 1;
  int y = 1;
  cout << 1 << endl;
  do
    {
      y = x*(y);
      cout << y << endl;
      x = x+1;
    }while (x < 10);
  return 0;
}
