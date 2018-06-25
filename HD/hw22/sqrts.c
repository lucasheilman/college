

/* print square roots in C language.  R. Brown, 9/2010 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
  int n;
  int max;
  printf("sqrt(n)\n--------\n");
  max = atoi(argv[1]);
  for (n=0;  n<=max;  n++)
    printf("%f\n", sqrt(n));
  return 0;
}

