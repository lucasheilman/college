#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct s {
  char *chars;
  int num;
};

int main(int argc, char *argv[])
{
  struct s item;
  int numm = atoi(argv[1]);
  item.chars = malloc(numm*sizeof(char));
  strcpy(item.chars, "apple");
  int i;
  for(i = 0; i < 8; i++)
    {
      item.chars[i] = 'l';
    }
  item.chars = realloc(item.chars,2*sizeof(char));
  item.num = 4;
  printf("%s\n", item.chars);
  printf("%d\n", item.num);
  free(item.chars);
}