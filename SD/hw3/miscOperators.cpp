#include <iostream>
using namespace std;
#include"/home/users/cs251/binary.h"

int main()
{
  char a = 3;
  char b = 3;
  cout << "a is assigned to be " << binary(a) << endl;
  cout << "b is assigned to be " << binary(b) << endl;
  char c = a | b;
  cout << "a | b is " << binary(c) << endl;
  int d = int (a) ;
  cout << "int of a is  " << d << endl;
  int e = sizeof(b);
  cout << "sizeof(b) is " << e << endl;
  return 0;
}
