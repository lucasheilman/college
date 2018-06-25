/* This file runs the shell 
Lucas Heilman 3/11/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

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

/* This function reads input and tokenizes it */
int read_name(struct name *n)
{
  char *line = NULL;
  size_t size;
  ssize_t nread;
  n->status = NORMAL;
  printf("Type a command: ");
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
  /* This loop processes the tokens and runs the specified command */
  while((strncmp(n.tok[0],"done",4) != 0)){
    if(ret == NORMAL)
      {
	printf("NORMAL\n");
	int ret;
	printf("I am the PARENT.  My pid is %d\n", getpid());
	if ((ret = fork()) < 0) 
	  {
	    printf("fork() FAILED");
	    perror("forkeg");
	    _exit(1);
	  }
	if (ret != 0) 
	  {
	    printf("I am the PARENT. My pid is %d, and fork() returned %d.\n", getpid(), ret);
	    wait();
	  } 
	else 
	  {
	    printf("I am the CHILD. My pid is %d, and fork() returned %d.\n", getpid(), ret);
	    int ret2;
	    if((strncmp(n.tok[0],"access",6) == 0))
	      {
		ret2 = access(n.tok[1], R_OK);
		if(ret2 == 0)
		  {
		    printf("You have read permission\n");
		  }
		else
		  {
		    printf("You do not have read permission for this reason: %s\n", strerror(errno));
		  }
		ret2 = access(n.tok[1], W_OK);
		if(ret2 == 0)
		  {
		    printf("You have write permission\n");
		  }
		else
		  {
		    printf("You do not have write permission for this reason: %s\n", strerror(errno));
		  }
		ret2 = access(n.tok[1], X_OK);
		if(ret2 == 0)
		  {
		    printf("You have execute permission\n");
		  }
		else
		  {
		    printf("You do not have execute permission for this reason: %s\n", strerror(errno));
		  }
	      }
	    else if((strncmp(n.tok[0],"chdir",5) == 0))
	      {
		ret2 = chdir(n.tok[1]);
		if(ret2 == 0)
		  {
		    printf("Directory changed successfully\n");
		  }
		else
		  {
		    printf("Directory change failed for this reason: %s\n", strerror(errno));
		  }
	      }
	    else if((strncmp(n.tok[0],"getcwd",6) == 0))
	      {
		char buff[1000];
		getcwd(buff, sizeof(buff));
		if(buff != NULL)
		  {
		    printf("Current working directory is: %s\n", buff);
		  }
		else
		  {
		    printf("Could not get current working directory for this reason: %s\n", strerror(errno));
		  }
	      }
	    else if((strncmp(n.tok[0],"getgid",6) == 0))
	      {
		ret2 = getgid();
		printf("Group ID: %i\n", ret2);
	      }
	    else if((strncmp(n.tok[0],"gethostid",9) == 0))
	      {
		ret2 = gethostid();
		printf("Host ID: %i\n", ret2);
	      }
	    else if((strncmp(n.tok[0],"getuid",6) == 0))
	      {
		ret2 = getuid();
		printf("User ID: %i\n", ret2);
	      }
	    else if((strncmp(n.tok[0],"rmdir",5) == 0))
	      {
		ret2 = rmdir(n.tok[1]);
		if(ret2 == 0)
		  {
		    printf("Directory removed successfully\n");
		  }
		else
		  {
		    printf("Directory removal failed for this reason: %s\n", strerror(errno));
		  }
	      }
	    else if((strncmp(n.tok[0],"setgid",6) == 0))
	      {
		int id = atoi(n.tok[1]);
		ret2 = setgid(id);
		if(ret2 == 0)
		  {
		    printf("Group set successfully\n");
		  }
		else
		  {
		    printf("Setting group failed for this reason: %s\n", strerror(errno));
		  }
	      }
	    else if((strncmp(n.tok[0],"setuid",6) == 0))
	      {
		int id = atoi(n.tok[1]);
		ret2 = setuid(id);
		if(ret2 == 0)
		  {
		    printf("User set successfully\n");
		  }
		else
		  {
		    printf("Setting user failed for this reason: %s\n", strerror(errno));
		  }
	      }
	    else if((strncmp(n.tok[0],"chmod",5) == 0))
	      {
		int mode = strtol(n.tok[2], 0, 8);
		ret2 = chmod(n.tok[1],mode);
		if(ret2 == 0)
		  {
		    printf("Permissions set successfully\n");
		  }
		else
		  {
		    printf("Setting permissions failed for this reason: %s\n", strerror(errno));
		  }
	      }
	    else if((strncmp(n.tok[0],"mkdir",5) == 0))
	      {
		ret2 = mkdir(n.tok[1]);
		if(ret2 == 0)
		  {
		    printf("Directory created successfully\n");
		  }
		else
		  {
		    printf("Directory creation failed for this reason: %s\n", strerror(errno));
		  }
	      }
	    else
	      {
		ret2 = execve(n.tok[0], n.tok, NULL);
		if(ret2 = 0)
		  {
		    printf("Executed successfully\n");
		  }
		else
		  {
		    printf("Execute failed for this reason: %s\n", strerror(errno));
		  }
	      }
	    _exit(1);
	  }
	printf("I am the PARENT. My pid is %d, and I'm signing off.\n", getpid());
      }
    else if(ret == TOO_MANY_TOKENS)
      {
	printf("TOO_MANY_TOKENS\n");
      }
    else
      {
	printf("ERROR\n");
      }
    n.tok = NULL;
    ret = read_name(&n);
  }
}
