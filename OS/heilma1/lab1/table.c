#include <stdio.h>

int main()
{
  printf("Enter a positive integer: ");
  int n;
  scanf("%d", &n);
  printf("N\t| N*N\n-----------------\n");
  int i;
  for(i = 1; i <= n; i++)
    {
      printf("%d\t| %d\n", i, i*i);
    }
}
