#include<iostream>
using namespace std;

int main()
{
  int x = 1;
  signed short val1, val2;
  while ( cin >> val1 >> val2 ) {
    ++x;
    if (x > 100000)
      cout << val1 << " " << val2 << " ";
  }
  cout << endl;
  return 0;
}
