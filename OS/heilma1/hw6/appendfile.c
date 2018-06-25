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
      FILE *inFile;
      FILE *outFile;
      char *buffer = NULL;
      size_t bufflen = 0; 
      
      inFile = fopen(n.tok[0], "r");
      outFile = fopen(n.tok[1], "a");
      if (inFile == NULL) 
	perror ("Error opening file");
      else {
	while (getline(&buffer, &bufflen, inFile) >= 0)
	  fprintf(outFile, "%s", buffer);
	fclose(inFile);
	fclose(outFile);
      }
    }
  else if(ret == TOO_MANY_TOKENS)
    {
      printf("TOO_MANY_TOKENS\n");
    }
  else
    {
      printf("ERROR\n");
    }
}
