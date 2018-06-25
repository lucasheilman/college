/* Server-side use of Berkeley socket calls -- receive one message and print 
   Requires one command line arg:  
     1.  port number to use (on this machine). 
   RAB 3/12 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h> 

#define MAXBUFF 100
#define MAXTOKS 3
#define NWORKERS 2

pthread_mutex_t gLock;

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

struct tdata {
  int clientd;
  struct tdata* link;
};

struct work_queue {
  struct tdata *start; /* address of first tdata in the queue, or 0 if none */
  struct tdata **end;  /* address of last link in queue, or of start if none */
} work_queue;

pthread_mutex_t qMutex;
pthread_cond_t qEmpty;

/* addq
     1 argument:  address of a tdata item
     State change:  The tdata item arg1 is appended to the end of 
	work_queue, adjusting work_queue's members to reflect the new item
     Return: none */
void addq(struct tdata *tdatap) {
  pthread_mutex_lock(&qMutex);
  if (work_queue.end == &work_queue.start)
    pthread_cond_broadcast(&qEmpty);
  *work_queue.end = tdatap;
  tdatap->link = 0;
  work_queue.end = &tdatap->link;
  pthread_mutex_unlock(&qMutex);
  return;
}

/* removeq
     No arguments
     State change:  If work_queue contains at least one item,
        remove the first item from work_queue, adjusting  work_queue 
        to reflect that removal. 
     Return: The address of the removed struct tdata item, or 0 if 
        work_queue was empty. */
struct tdata *removeq() {
  pthread_mutex_lock(&qMutex);
  while (work_queue.start == 0)
    /* assert: there are no elements in work_queue */
    pthread_cond_wait(&qEmpty, &qMutex);  
  /* assert:  there is at least one element in work_queue */
  struct tdata *tmp = work_queue.start;
  work_queue.start = tmp->link;
  if (work_queue.start == 0)
    /* assert:  no remaining elements in work_queue */
    work_queue.end = &work_queue.start;
  pthread_mutex_unlock(&qMutex);
  tmp->link = 0;
  return tmp;
}

void* process_requests(void* id)
{
  struct tdata *td2 = removeq();
  int thread_id = *((int *)id);
  struct name n;
  FILE *logFile;
  logFile = fopen("log.txt", "a");
  int ret1;
  char *line;
  size_t size1;
  ssize_t nread;
  n.status = NORMAL;
  char buff[MAXBUFF];  /* message buffer */
  int ret;  /* return value from a call */
  char timestamp[30];
  char *pch;
  int i;
  FILE *inFile;
  char *buffer;
  size_t bufflen;
  while(1)
  {
    i = 0;
    line = NULL;
    buffer = NULL;
    bufflen = 0;
    if ((ret = recv(td2->clientd, buff, MAXBUFF-1, 0)) < 0)
    {
      perror("recv()");
    }
    time_t now = time(NULL);
    strftime(timestamp, 30, "%a, %d %b %Y %T %Z", gmtime(&now));
    fprintf(logFile, "%d: %s: %s\n", thread_id, timestamp, buff);
    line = &buff[0];
    pch = strtok(line, " \t\n\r\v\f");
    n.tok = malloc(sizeof(char**) * MAXTOKS);
    while(pch != NULL)
    {
      if(i == MAXTOKS)
	    {
	      n.status = TOO_MANY_TOKENS;
	      break;
	    }
      n.tok[i] = pch;
      i++;
      pch = strtok(NULL, " \t\n\r\v\f");
    }
    n.count = i;
    ret1 = n.status;
    int linesize;
    if(ret1 == NORMAL)
    {
      if(n.count != 3 || strcmp(n.tok[0], "GET") != 0)
      {
        return;
      }
      inFile = fopen(n.tok[1], "r");
      if (inFile == NULL) 
      {
        return;
      }
      else 
      {
        while ((linesize = getline(&buffer, &bufflen, inFile)) >= 0)
        {
          if ((ret = send(td2->clientd, buffer, linesize, 0)) < 0) 
          {
            perror("send()");
          }
        }
        fclose(inFile);
      }
    }
    else if(ret1 == TOO_MANY_TOKENS)
    {
      fclose(logFile);
      return;
    }
    else
    {
      fclose(logFile);
      return;
    }
  }
}

int main(int argc, char **argv) {
  char *prog = argv[0];
  int port;
  int serverd;  /* socket descriptor for receiving new connections */

  if (argc < 2) {
    printf("Usage:  %s port\n", prog);
    return 1;
  }
  port = atoi(argv[1]);

  if ((serverd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("%s ", prog);
    perror("socket()");
    return 1;
  }
  
  struct sockaddr_in sa;
  sa.sin_family = AF_INET;
  sa.sin_port = htons(port);
  sa.sin_addr.s_addr = INADDR_ANY;

  if (bind(serverd, (struct sockaddr*) &sa, sizeof(sa)) < 0) {
    printf("%s ", prog);
    perror("bind()");
    return 1;
  }
  if (listen(serverd, 5) < 0) {
    printf("%s ", prog);
    perror("listen()");
    return 1;
  }

  
  int clientd;  /* socket descriptor for communicating with client */
  struct sockaddr_in ca;
  int size = sizeof(struct sockaddr);

  printf("Waiting for a incoming connection...\n");
  
  int ret;
  pthread_t handles[NWORKERS]; 
  int id[NWORKERS], i;
  work_queue.start = 0;
  work_queue.end = &work_queue.start;
  pthread_mutex_init(&qMutex, NULL);
  pthread_cond_init(&qEmpty, NULL);
  struct tdata td[NWORKERS];
  pthread_mutex_init(&gLock, NULL);

  for (i = 0; i < NWORKERS; ++i ) {
    if ((clientd = accept(serverd, (struct sockaddr*) &ca, &size)) < 0) {
      printf("%s ", prog);
      perror("accept()");
      return 1;
    }
    td[i].clientd = clientd;
    addq(&td[i]);
    id[i] = i; 
    pthread_create(&handles[i], NULL, process_requests, (void*)&id[i]);
  }

  for ( i = 0; i < NWORKERS; ++i ) {
    pthread_join(handles[i], NULL);
  }
  pthread_mutex_destroy(&gLock); 

  if ((ret = close(serverd)) < 0) {
    printf("%s ", prog);
    perror("close(serverd)");
    return 1;
  }
}
