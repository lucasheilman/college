/* print square roots in C++ language.  R. Brown, 9/2010 */

#include <iostream>
#include <cmath>

using namespace std;


int main()
{ int n;
  int result = 0;
  int i;

  cout << "enter a positive integer: " << endl;
  i = 0;
  while (i<= n){
    result = result +i*i;
    i++;
  }
    
  cout << "The sum of the first %d squares is %d.\n" << n << result << endl;
  return 0;
}
