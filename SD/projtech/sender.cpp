/* Client-side use of Berkeley socket calls -- send one message to server
   Requires two command line args:  
     1.  name of host to connect to (use  localhost  to connect to same host)
     2.  port number to use. 
   RAB 4/16 */

#include <iostream>
#include "Socket.h"
#include <cstring>

using namespace std;

#define MAXBUFF 100

int main(int argc, char **argv) {
  char *prog = argv[0];
  char *host;
  int port;
  int ret;  /* return value from a call */

  if (argc < 3) {
    cout << "Usage:  " << prog << " host port" << endl;
    return 1;
  }
  host = argv[1];
  port = atoi(argv[2]);
  ServerSocket ssock(port);
  Socket sock(host, port);
  if (sock.getConnected()) 
    cout << "Connected." << endl;
  else {
    cout << "Could not connect, aborting" << endl;
    return 1;
  }
  
  char buff[MAXBUFF];  /* message buffer */
  char buff2[MAXBUFF];
  int nchars;  /* number of bytes recently read */
  cout << "Enter a one-line message to send (max " << MAXBUFF-1 << 
    " chars)" << endl;
  while(strcmp(buff,"DONE")){
    if (!cin.getline(buff, MAXBUFF)) {
      cout << "Error or end of input -- aborting" << endl;
      return 1;
    }
    nchars = cin.gcount();
    if ((ret = sock.send(buff, nchars-1)) < 0)
      return 1;
    cout << ret << " characters sent" << endl;
    sock.recv(buff2,MAXBUFF-1);
    cout <<buff2 <<endl;
  }
  return 0;
}
