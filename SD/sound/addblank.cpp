#include<iostream>
using namespace std;

int main()
{
  int x = 1;
  signed short val1, val2;
  while (x < 100000)
    cout << 0 << " ";
  while ( cin >> val1 >> val2 ) {
    cout << val1 << " " << val2 << " ";
  }
  cout << endl;
  return 0;
}
