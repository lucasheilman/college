/* Server-side use of Berkeley socket calls -- receive one message and print
   Requires one command line arg:  
     1.  port number to use (on this machine). 
   RAB 4/16 */

#include <iostream>
#include "Socket.h"
#include <cstring>

using namespace std;

#define MAXBUFF 100

int main(int argc, char **argv) {
  char *prog = argv[0];
  //char *host = argv[1];
  int port;

  if (argc < 2) {
    cout << "Usage:  " << prog << " port" << endl;
    return 1;
  }
  port = atoi(argv[1]);

  ServerSocket ssock(port);
  if (ssock.getBound())
    cout << "port " << port << " bound to server socket" << endl;
  else {
    cout << "could not bind port " << port << " to server socket, aborting"
	 << endl;
    return 1;
  }
  
  Socket *csockp = ssock.accept();
  char buff[MAXBUFF];  /* message buffer */
  int ret;  /* return value from a call */
  while(strcmp(buff,"DONE")){
    ret = csockp->recv(buff, MAXBUFF-1);

    buff[ret] = '\0';  // add terminating nullbyte to received array of char
    cout << "Received message (" << ret << " chars):" << endl 
	 << buff << endl;
    csockp->send("ACK",4);
  }

  delete csockp;
  return 0;
}
