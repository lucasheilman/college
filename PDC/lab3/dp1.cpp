#include <iostream>
using namespace std;
#include <cmath>
#include "Sync.h"
#include "mpi.h"
int main(int argc, char** argv) {
  int my_rank; 
  int nprocs;  
  MPI_Status   status; 
  int head = 0;
  int tag = 0;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  if(my_rank == head) {
    SyncServer::run();
  } 
  else {
    Sync s1(0);
    s1.send(PRINT, "hello");
    s1.recv(ACK);
    s1.send(QUIT, "");
    s1.recv(ACK);
  }
  MPI_Finalize();
}
