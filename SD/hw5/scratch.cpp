#include<iostream>
using namespace std;

int main()
{
  int a = 5;
  if ( a+7 == 14 ) {
    int b = 3;
    cout << "b is " << b << endl;
  } else {
    int c = 7;
    cout << "c%a is " << (c%a) << endl;
  }
  return 0;
}
