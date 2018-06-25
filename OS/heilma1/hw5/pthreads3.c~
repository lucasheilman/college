#include <pthread.h>
#include <stdio.h>

pthread_mutex_t count_mutex;
int val = 10;

void *pt_pid(void *x_void_ptr)
{
  pthread_mutex_lock(&count_mutex);
  val = val + 1;
  pthread_mutex_unlock(&count_mutex);
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
  pthread_mutex_lock(&count_mutex);
  val = -1*val;
  pthread_mutex_unlock(&count_mutex);
  printf("I am the MAIN, and I successfully launched a pthread.\n");  
  if (pthread_join(pt, NULL)) 
    {
      fprintf(stderr, "Error joining thread\n");
      return 2;
    }
  printf("I am the MAIN, and the pthread has finished.\n");
  printf("Value of val: %d\n", val);
  return 0;

}
