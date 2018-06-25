#include <iostream>
using namespace std;
#include <cmath>
#include "dp.h"
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
  if(my_rank == (nprocs-1)) {
    SyncServer::run();
  } 
  else {
    Sync s1(nprocs-1);
    s1.send(PRINT, "hello");
    s1.recv(ACK);
    s1.send(ECHO, "hello2");
    cout << s1.recv(ACK) << endl;
    s1.send(QUIT, "");
    s1.recv(ACK);
  }
  MPI_Finalize();
}
