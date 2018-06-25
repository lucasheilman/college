#include <iostream>
using namespace std;
int gced(int A, int B) {
    int gced = 1;
    if(A < B){
        for(int i = 0; i < A; i++){
	  cout << A%i << endl;
            if((A%i == 0) && (B%i == 0)){
                cout << "gcd is: " << gced << endl;
                gced = i;
            }
        }
    }
    else{
        for(int i = 0; i < B; i++){
            if(A%i == 0 && B%i == 0){
                gced = i;
            }
        }
    }
    return gced;
}

int main(){
  int A = 6;
  int B = 9;
  cout << gced(A,B) << endl;
}
