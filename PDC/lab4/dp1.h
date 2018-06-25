#include <iostream>
using namespace std;
#include "mpi.h"
#define NONE -1
#define MAXSMSG 100

enum SyncMessageType { 
  QUIT, ACK, PRINT, ECHO, GETCHOP, PUTCHOP
};

class SyncServer {
public:
  int run() {
    char buff[MAXSMSG+1];
    int nprocs;
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    int chop[nprocs-1];
    int count;
    MPI_Status status;  // holds status info from most recent MPI call
    while (1) { 
      MPI_Recv(buff, MAXSMSG, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      MPI_Get_count(&status, MPI_CHAR, &count);
      /* cout << "Message received from " << status.MPI_SOURCE << ", type "
	 << status.MPI_TAG << ", count " << count << endl; */
      buff[count] = '\0';
      switch ((enum SyncMessageType) status.MPI_TAG) {
      case QUIT: {
	char msg[] = "bye";
	MPI_Send(msg, strlen(msg), MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD);
	cout << "Shutting down MPI_COMM_WORLD" << endl;
	MPI_Abort(MPI_COMM_WORLD, MPI_SUCCESS);
	return 0;
	break;
      }
      case PRINT:
	cout << buff << endl;
	char empty[1];  empty[0] = '\0';
	MPI_Send(empty, 0, MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD);
	break;
      case ECHO:
        MPI_Send(buff, strlen(buff), MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD);
        break;
      case GETCHOP:{
        int q  = status.MPI_SOURCE;
        if(strcmp(buff, "L") == 0){
          count = (q+1)%(nprocs-1);
        }
        else if(strcmp(buff, "R") == 0){
          count = q;
        } 
        if(chop[count] == NONE){
          chop[count] = q;
          char empty[1]; empty[0] = '\0';
          MPI_Send(empty,strlen(empty),MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD);
        }
        else if(chop[count] == status.MPI_SOURCE){
          char error[] = "ERROR";
          MPI_Send(error, strlen(error),MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD);
        }
        else{
          char no[] = "NO";
          MPI_Send(no, strlen(no),MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD); 
        }
        break;
      }
      case PUTCHOP:{
        int p = status.MPI_SOURCE;
        if(strcmp(buff,"L")==0){
          count = (p+1)%(nprocs-1);
        }
        else if(strcmp(buff, "R")==0){
          count = p;
        }
        if(chop[count] == p){
          chop[count] = NONE;
          char empty[1]; empty[0] = '\0';
          MPI_Send(empty,strlen(empty), MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD); 
        }
        else{
          char error[] = "ERROR";
          MPI_Send(error, strlen(error),MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD);
        }
        break;
      }
      default: {
	char msg[] = "Unrecognized type ";
	cout << msg << status.MPI_TAG << endl;
	MPI_Send(msg, strlen(msg), MPI_CHAR, status.MPI_SOURCE, ACK, MPI_COMM_WORLD);
      }
      }
    }
  }
};
  
class Sync {
protected:
  int server;  // rank of server process

public:
  Sync(int server_rank) { 
    server = server_rank;
  }

  void send(enum SyncMessageType type, const char * msg) const {
    // cout << "send" << endl;
    int len = strlen(msg);
    if (len > MAXSMSG)
      len = MAXSMSG;
    MPI_Send((void *) msg, len, MPI_CHAR, server, type, MPI_COMM_WORLD); 
  }

  void send(enum SyncMessageType type) const {
    // cout << "send" << endl;
    char empty[1];  empty[0] = '\0';
    MPI_Send(empty, 0, MPI_CHAR, server, type, MPI_COMM_WORLD); 
  }

  // returns a dynamically allocated string, which must be deallocated
  char * recv(enum SyncMessageType type) {
    // cout << "recv" << endl;
    MPI_Status status;  // holds status info from most recent MPI call
    int count;
    char * buff = new char[MAXSMSG+1];
    MPI_Recv(buff, MAXSMSG, MPI_CHAR, server, type, MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_CHAR, &count);
    buff[count] = '\0';
    return buff;
  }
};

