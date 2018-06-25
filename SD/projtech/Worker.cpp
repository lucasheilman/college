/* Implementation module for multithreaded server thread class
   RAB 5/2/16 */

#include <iostream>
#include <cstring>
#include "Worker.h"
#include <fstream>
#include <string>

int Worker::MAXBUFF = 100;

Worker::Worker(int i, Socket *sp, const ControlData *cdp) 
  : thread(&Worker::doWork, this, cdp), id(i), sockp(sp), state(RUNNING) {}

/* NOTE about thread constructor call above:  
   methods have an implicit first argument, namely, the object whose state 
   variables they act on.  That object argument must be explicitly passed 
   for this 2-argument thread constructor */

Worker::~Worker() {
  delete sockp;
  sockp = 0;
}

void Worker::doWork(const ControlData *cdp) {
  char buff[MAXBUFF];  /* message buffer */
  int ret;  /* return value from a call */

  cout << "[" << id << "] started" << endl;
  // cout << "[" << id << "] socket <" << sockp->getDescriptor() << ">" << endl; //DEBUG


  // send welcome message
  if (cdp->contin) 
    strcpy(buff, "ACK");
  else
    strcpy(buff, "DONE");
  sockp->send(buff, strlen(buff));  
  char line1[5];
  while (strcmp(buff, "DONE") != 0) {
    ret = sockp->recv(buff, MAXBUFF-1);

    buff[ret] = '\0';  // add terminating nullbyte to received array of char
    cout << "[" << id << "] Received message (" << ret << " chars):" << endl 
	 << buff << endl;
    for(int i;i<5;i++){
      line1[i] = buff[0];
    }
    if(strcmp(line1,"LINE1")){
      int len;
      for(len = 0; buff[len+6] != '\0';len++){}
      len++;
      char file[len];
      for(int a = 0;a<len;a++){
	file[a] = buff[a+6];
      }
      ifstream g(file);
      int a=0;
      char *line[100];
      getline(g,line[a],'\n');
      sockp->send(line,100);
    }
    if (strcmp(buff, "DONE") == 0 || !cdp->contin) {
      strcpy(buff, "DONE");
      sockp->send(buff, 4);
      cout << "[" << id << "] sent termination message" << endl;
    } else if (strncmp(buff, "MSG ", 4) == 0) {
      sockp->send("ACK", 3);
      cout << "[" << id << "] sent acknowledgment" << endl;
    } else {
      sockp->send("NACK", 4);
      cout << "[" << id << "] sent negative acknowledgment" << endl;
    }
  }

  // receive END message from client
  if ((ret = sockp->recv(buff, MAXBUFF-1)) != -1) {
    buff[ret] = '\0';
    cout << "[" << id << "] Received " << buff << " from client" << endl;
  }
  state = DONE;
}

