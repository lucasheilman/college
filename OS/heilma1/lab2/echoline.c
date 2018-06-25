#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTOKS 3

struct name {
  char **tok;
  int count;
  int status;
};

enum status_value {
  NORMAL,
  EOF_OR_ERROR,
  TOO_MANY_TOKENS
};

int read_name(struct name *n)
{
  char *line = NULL;
  size_t size;
  ssize_t nread;
  n->status = NORMAL;
  if((nread = getline(&line, &size, stdin)) == -1)
    {
      n->status = EOF_OR_ERROR;
    }
  char *pch;
  pch = strtok(line, " \t\n\r\v\f");
  n->tok = malloc(sizeof(char**) * MAXTOKS);
  int i = 0;
  while(pch != NULL)
    {
      if(i == MAXTOKS)
	{
	  n->status = TOO_MANY_TOKENS;
	  break;
	}
      n->tok[i] = pch;
      i++;
      pch = strtok(NULL, " \t\n\r\v\f");
    }
  n->count = i;
  return n->status;
}

int main()
{
  struct name n;
  int ret;
  ret = read_name(&n);
  if(ret == NORMAL)
    {
      printf("NORMAL\n");
      printf("%s, ", n.tok[n.count-1]);
      int i;
      for(i = 0; i < n.count-1; i++)
	{
	  printf("%s ", n.tok[i]);
	}
      printf("\n");
    }
  else if(ret == TOO_MANY_TOKENS)
    {
      printf("TOO_MANY_TOKENS\n");
      printf("%s, ", n.tok[n.count-1]);
      int i;
      for(i = 0; i < n.count-1; i++)
	{
	  printf("%s ", n.tok[i]);
	}
      printf("\n");
    }
  else
    {
      printf("ERROR\n");
    }
}