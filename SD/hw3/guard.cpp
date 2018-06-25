#include <iostream>
using namespace std;

int main()
{
  int a = 3;
  int b = 3;
  cout << "a is assigned to be " << a << endl;
  cout << "b is assigned to be " << b << endl;
  bool c = a==b;
  cout << "a == b is " << c << endl;
  bool d = a>b;
  cout << "a > b is " << d << endl;
  bool e = c && d;
  cout << "(a==b) and (a>b) is " << e << endl;
  return 0;
}
