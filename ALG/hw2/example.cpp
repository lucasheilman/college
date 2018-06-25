#include <iostream>
using namespace std;
 
void recursion(int n)
{
  int x = 2 * 3;
  x = x * 3;
 
  if (n < 100)
    recursion(n + 1);
}  
 
int main() 
{
  recursion(1);
 
  return 0;
}
