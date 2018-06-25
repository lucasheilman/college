#include<iostream>
using namespace std;

int main()
{
  signed short val;
  while ( cin >> val ) {
    val *= 2;
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
