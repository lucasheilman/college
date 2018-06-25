/* print square roots in C++ language.  R. Brown, 9/2010 */

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){
  cout << "sqrt(n)" << endl << "--------" << endl;
  int max;
  max = atoi(argv[1]);
  for (int n=0;  n<=max;  n++)
    cout << sqrt(n) << endl;
  return 0;
}

