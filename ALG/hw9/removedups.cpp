#include <iostream>
using namespace std;

int main(){
    int a[20];
    for(int i = 0; i < 20; i++){
      a[i] = rand()%100;
    }
    int b[sizeof(a)/4];
    int summ = 0;
    b[0] = a[0];
    for(int j = 1; j < sizeof(a)/4; j++){
      if(a[j] != b[j-1]){
	b[j] = a[j];
      }
      else{
	summ = summ + 1;
      }
    }
    cout << "[";
    for(int x = 0; x < (sizeof(b)/4)-1-summ; x++){
	cout << b[x] << ",";
    }
    cout << b[sizeof(b)/4-summ] << "]" << endl;
}
