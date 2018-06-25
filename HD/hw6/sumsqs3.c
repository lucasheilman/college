/* example of iteration in C language.  RAB 9/10 */

#include <stdio.h>

int main() {
  int n;
  int result = 0;  
  int i;

  printf("Enter a positive integer:  ");
  scanf("%d", &n);

  i = 0;
  do {
    result = result + i*i;
  } while (i <= n-1);

  printf("The sum of the first %d squares is %d.\n", n, result);
  return 0;  
}
