#include<iostream>
using namespace std;

void func(int a[], float ***f)
{
  float **root;
  root = new float*[3];
  for ( unsigned i = 0; i < 3; ++i )
    root[i] = new float[2];
  for ( short i = 0; i < 3; ++i )
    **(root+i) = 2*a[i];
  *f = root;
}

int main()
{
  int a[] = {5, 4, 3};
  float **b;
  func(a, &b);
  cout << a[0] << " " << *(b[0]) << " " << *(b[1]) << " " << *(b[2]) << endl;
}
