#include <iostream>
using namespace std;

int func(int arg)
{
  arg = arg + 2;
  return arg;
}

int funcp(int *argp)
{
  *argp = (*argp) + 2;
  return *argp;
}

int main ()
{
  int i = 17;
  double f = -4.2;
  int *ip = &i;
  double *fp = &f;
  cout << "Initial values:  i == "<< i << ", *ip == "<< *ip
       <<", f == "<< f << ", fp == " << *fp<< endl;
  i = i*3;
  *fp = *fp*1.5;
  cout << "After multiplying:  i == "<< i << ", *ip == "<< *ip
       <<", f == "<< f << ", fp == " << *fp<< endl;
  double f2 = 2.5;
  fp = &f;
  i = *ip*i;
  cout << "After defining f2:  i == "<< i << ", *ip == "<< *ip
       <<", f == "<< f << ", fp == " << *fp<< ", == " << f2 << endl;
  cout << "func(i) returns " << func(i);
  cout << ", i == " << i << ", *ip == " << *ip << endl;
  cout << "func(i) returns " << func(*ip);
  cout << ", i == " << i << ", *ip == " << *ip << endl;
  cout << "func(i) returns " << funcp(ip);
  cout << ", i == " << i << ", *ip == " << *ip << endl;
  cout << "func(i) returns " << funcp(&i);
  cout << ", i == " << i << ", *ip == " << *ip << endl;
}
