#include<iostream>
using namespace std;

void f(short *p, short &r, short *&pr)
{
  r = *p + 1;
  pr = &r;
  *pr = *p;
}

int main()
{
  short a=1, b=2, c=3;
  short *q = &c;
  f(&a, b, q);
  *q = 4;
  cout << a << b << c << endl;
}
