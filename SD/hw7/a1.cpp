#include <iostream>
using namespace std;

void printarray (int arg[], int length) {
 for (int n=0; n<length; n++)
 cout << arg[n] << " ";
 cout << "\n";
}

int main(){
  int y, z=0, a=1;
  int arr[10];
  for (int x=0; x<11;x++){
    y = z+a;
    arr[x] = y;
    a=z;
    z=y;
  }
  printarray(arr,10);
}
