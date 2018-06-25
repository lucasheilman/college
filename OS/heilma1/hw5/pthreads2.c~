#include <pthread.h>
#include <stdio.h>


void *pt_pid(void *x_void_ptr)
{
  printf("I am the PTHREAD. My pid is %d\n", getpid());
  return NULL;
}

int main() {
  printf("I am the MAIN. My pid is %d\n", getpid());
  pthread_t pt;
  int x = 0;
  if (pthread_create(&pt, NULL, pt_pid, &x)) 
    {
      fprintf(stderr, "Error creating thread\n");
      return 1;
    }
  printf("I am the MAIN, and I successfully launched a pthread.\n");  
  if (pthread_join(pt, NULL)) 
    {
      fprintf(stderr, "Error joining thread\n");
      return 2;
    }
  printf("I am the MAIN, and the pthread has finished.\n");
  return 0;

}
