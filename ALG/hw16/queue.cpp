#include <iostream>
using namespace std;

class Queue{
private:
  int pointer = 0;
public:
  int a[];
  
  Queue(int i){
    int a[i];
    for(int x = 0; x < i; x++){
      a[x] = 0;
    }
  }
  
  void inject(int i){
    a[pointer] = i;
    cout << i << " is now in spot " << pointer << endl;
    pointer = pointer+1;
  }

  void eject(){
    cout << "Removed front val: " << a[0]<< endl;
    a[0] = 0;
    for(int i = 0; i < pointer-1; i++){
      a[i] = a[i+1];
    }
    pointer = pointer - 1;
  }
  void print(){
    cout << '[';
    for(int i = 0; i < pointer-1; i++){
      cout << a[i] << ',';
    }
    cout << a[pointer-1] << ']' << endl;
  }
};

int main(){
  Queue st = Queue(5);
  st.inject(3);
  st.print();
  st.inject(4);
  st.print();
  st.eject();
  st.print();
  st.inject(5);
  st.print();
  st.inject(6);
  st.print();
  st.eject();
  st.print();
}
