#include <iostream>
using namespace std;

int operate(int& a, int &b);
  
int main(){
  int x=4, y=6;
  cout << operate(x,y) << endl; 
}

int operate(int& a, int& b){
  return (a*b);
}
