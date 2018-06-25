/* test program for lib.c */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "lib.h"

int main()
{
  int rv;
  char *msg = "Hello, world!\n";
  rv = dub2(1,5);
  if(rv < 0)
  {
    printf("dub2 ERROR: %s\n", strerror(errno));
  }

  printf("dub2(1,5) returns %d\n", rv);

  printf("Test of write on fd %d:\n", rv);
  write(rv, msg, strlen(msg));
  printf("getpid: %d\n", getpid());
  rv = lh_mycall();
  if(rv < 0)
  {
    printf("mycall ERROR: %s\n", strerror(errno));
  }
  printf("lh_mycall: %d\n", rv);
  
  rv = lh_getval();
  if(rv < 0)
  {
    printf("getval ERROR: %s\n", strerror(errno));
  }
  printf("lh_getval: %d\n", rv);
  rv = lh_putval(5);
  if(rv < 0)
  {
    printf("putval ERROR: %s\n", strerror(errno));
  }  
  
  rv = lh_getval();
  if(rv < 0)
  {
    printf("getval ERROR: %s\n", strerror(errno));
  }
  
  printf("lh_getval: %d\n", rv);
  
  

  return 0;
}
