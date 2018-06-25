#include <iostream>
using namespace std;

class Stack{
private:
  int pointer = 0;
public:
  int a[];
  
  Stack(int i){
    int size = i;
    int a[i];
  }
  
  void push(int i){
    a[pointer] = i;
    cout << i << " is now in spot " << pointer << endl;
    pointer = pointer+1;
  }

  void pop(){
    cout << "Removed last val: " << a[pointer-1]<< endl;
    a[pointer-1] = 0;

    pointer = pointer - 1;
  }
};

int main(){
  Stack st = Stack(5);
  st.push(3);
  st.push(4);
  st.pop();
}
  
