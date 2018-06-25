#include <iostream>
using namespace std;
#include <sys/select.h>
#include <cstdlib>
#include <cmath>
#include "dp.h"
#include "mpi.h"

void stosleep(long msec){
  struct timeval tv;
  tv.tv_sec = msec/1000;
  tv.tv_usec = 1000 * msec % 1000000;
  select(0, NULL,NULL, NULL, &tv);
}

int main(int argc, char** argv) {
  int my_rank; 
  int nprocs;  
  MPI_Status   status; 
  int head = 0;
  int tag = 0;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  srand(my_rank);
  if(my_rank == (nprocs-1)) {
    SyncServer::run();
  } 
  else {
    Sync s1(nprocs-1);
    while(true){
      stosleep(rand()%2000);
      cout << "Process " << my_rank << " retrying for it's right chopstick" << endl;
      s1.send(GETCHOP,"L" );
      s1.recv(ACK);
      cout << "Process " << my_rank << " now possesses chopstick right" << endl;
      cout << "Process " << my_rank << " retrying for it's left chopstick" << endl;
      s1.send(GETCHOP, "R");
      s1.recv(ACK);
      cout << "Process " << my_rank << " now possesses chopstick left" << endl;
      cout << "Process " << my_rank << " is now eating" << endl;
      s1.send(PUTCHOP, "L");
      s1.recv(ACK);
      s1.send(PUTCHOP, "R");
      s1.recv(ACK);
    }
  }
  MPI_Finalize();
}
