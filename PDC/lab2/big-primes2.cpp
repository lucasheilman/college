#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "mpi.h"
using namespace std;

int isprime(long arr[],const long long big){
  for(int i = 0; i < 78498; i++){
    if(big > arr[i]){
      if(big % arr[i] == 0){
        cout << big <<" is not prime and the divisor is " << arr[i] << endl;
        return 0;
      }
    }
  }
  cout << big << " is prime!" << endl;
  return 1;
}

int main(int argc, char** argv){
  MPI_Init(&argc, &argv);
  int r; 
  MPI_Comm_rank(MPI_COMM_WORLD, &r);
  int nprocs;
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  MPI_Status status;
  srand(r);
  long arr[78498];
  ifstream file("primes.list");
  for(int i = 0; i < 78498;i++){
    file >> arr[i];
  }
  int prime = 0;
  if(r == 0){
    while(prime == 0){
      const long long M = 100000;
      long long bigrand = (rand() % M);
      bigrand += (rand() % M)*M;
      bigrand += (rand() % M)*M*M;
      if(bigrand < 0){
        bigrand = -bigrand;
      }
      prime = prime || isprime(arr,bigrand);
      if(prime == 1){
        MPI_Finalize();
      }
      if(prime == 0){
        for(int source = 1; source < nprocs; source++){
          MPI_Send(&prime,1,MPI_INT,source,0,MPI_COMM_WORLD); 
          MPI_Recv(&prime,1,MPI_INT,source, 0, MPI_COMM_WORLD, &status);
          if(prime == 1){
            for(int source = 1; source < nprocs; source++){
              MPI_Send(&prime, 1, MPI_INT, source, 0, MPI_COMM_WORLD);
            }
            MPI_Finalize();
          }
        } 
      }
      else{
        for(int source = 1; source < nprocs; source++){
          MPI_Send(&prime, 1, MPI_INT, source,0,MPI_COMM_WORLD);
        }
        MPI_Finalize();
      }
    }
  }
  else{
    while(prime == 0){
      const long long M = 100000;
      long long bigrand = (rand() % M);
      bigrand += (rand() % M)*M;
      bigrand += (rand() % M)*M*M;
      if(bigrand < 0){
        bigrand = -bigrand;
      }
      prime = prime || isprime(arr,bigrand);
      if(prime == 0){
        MPI_Send(&prime,1,MPI_INT,0,0,MPI_COMM_WORLD);
        MPI_Recv(&prime, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
      }
      else{
        MPI_Send(&prime,1,MPI_INT,0,0,MPI_COMM_WORLD);
        MPI_Finalize();
      }
    }
  }
}
