#include <iostream>
using namespace std;

int main(){
  int size;
  cin >> size;
  int *memory;
  memory  = new int[size];
  int count = 0;
  int x;
  while(cin >> x){
    memory[count] = x;
    count++;
  }
  int sum;
  for (int i = 0; i<size;i++){
    sum = sum + memory[i];
  }
  cout << (sum/size) << endl;
}
    
    
