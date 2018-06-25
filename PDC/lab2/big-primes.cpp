#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

bool isprime(long arr[],const long long big){
  for(int i = 0; i < 78498; i++){
    if(big > arr[i]){
      if(big % arr[i] == 0){
        cout << "divisor is " << arr[i] << endl;
        return false;
      }
    }
  }
  return true;
}

int main(){
  long arr[78498];
  ifstream file("primes.list");
  for(int i = 0; i < 78498;i++){
    file >> arr[i];
  }
  const long long M = 1000000000;
  long long bigrand = (rand() % M);
  bigrand += (rand() % M)*M;
  bigrand += (rand() % M)*M*M;
  bigrand += (rand() % M)*M*M*M;
  bigrand += (rand() % M)*M*M*M*M;
  bigrand += (rand() % M)*M*M*M*M*M;
  bigrand += (rand() % M)*M*M*M*M*M*M;
  if(bigrand < 0){
    bigrand = -(bigrand);
  }
  cout << "bigrand is: " << bigrand << endl;
  bool prime = isprime(arr,bigrand);
  if(prime){
    cout << "it is prime!" << endl;
  }
  else{
    cout << "it is not prime!" << endl;
  }
}
