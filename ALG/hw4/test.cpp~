#include<iostream>
using namespace std;
#include"elapsed_time.h"

int main()
{
  int n = 100;
  int x;
  start_timer(); // this function is from elapsed_time.h
    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i; ++j ) {
	for ( int k = 0; k < j; ++k ) {
	  x = x + 5;
	}
      }
    }
  double cycles = elapsed_time();  // also from elapsed_time.h

  cout << " Total cycles: " << cycles << endl;
}
