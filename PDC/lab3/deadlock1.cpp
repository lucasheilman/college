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
  bool istrue;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  srand(my_rank);
  if(my_rank == (nprocs-1)) {
    SyncServer::run();
  } 
  else {
    bool gotL = false;
    bool gotR = false;
    Sync s1(nprocs-1);
    while(true){
      while(!gotL){
        cout << "Process " << my_rank << " retrying for its left chopstick" << endl;
        s1.send(GETCHOP,"L" );
        s1.recv(ACK);
        int count;
	MPI_Get_count(&status, MPI_BYTE,&count);
        if(count != 0){
          gotL = true;
          cout << "Process " << my_rank << " now possesses chopstick left" << endl;
          break;
        }
      }
      stosleep(rand()%1000);
      while(!gotR){
        cout << "Process " << my_rank << " retrying for its right chopstick" << endl;
        s1.send(GETCHOP, "R");
        s1.recv(ACK);
        int count;
        MPI_Get_count(&status, MPI_BYTE, &count);
        if(count != 0){
          gotR = true;
          cout << "Process " << my_rank << " now possesses chopstick left" << endl;
          break;
        }
      }
      s1.send(PUTCHOP, "L");
      s1.recv(ACK);
      s1.send(PUTCHOP, "R");
      s1.recv(ACK);
      gotL = false;
      gotR = false;
    }
  }
  MPI_Finalize();
}
