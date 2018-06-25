#include<iostream>
using namespace std;
#include"elapsed_time.h"
#include <math.h>

void recursion(int n)
{

  for(int i=0;i<100;i++)
  {
    int x = sin(0.8+0.234);
  }

  if (n > 0) {
    recursion(n/2);
    recursion(n/2);
  }
} 
int main()
{
  int n = 100;
  start_timer(); // this function is from elapsed_time.h
  recursion(n);
  double cycles = elapsed_time();  // also from elapsed_time.h
  cout << " Total cycles: " << cycles << endl;
}


