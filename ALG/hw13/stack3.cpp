#include <iostream>
#include "elapsed_time.h"
using namespace std;

struct Node {
  int x;
  Node *next;
};

class linkedStack{
private:
  Node * head;
public:
  linkedStack(){
    head = NULL;
  }
  void push(Node * newNode){
    head = newNode;
  }
    

  void pop(){
    if(head  == NULL){
      cout << "Nothing to remove" << endl;
    }
    Node *new_pointer = head;
    head = head -> next;
    delete new_pointer;
  }
  void print(){
    Node * p = head;
    Node * q = head;
    while(q){
      p = q;
      cout << "Value: " << p -> x << endl;
      q = p -> next;
    }
  }
};

int main(){
  Node * A = new Node;
  A -> x = 1;
  Node * B = new Node;
  B -> x = 2;   
  Node * C = new Node;
  C -> x = 3; 
  Node * D = new Node;
  D -> x = 4; 
  Node * E = new Node;
  E -> x = 5;
  Node * F = new Node;
  F -> x = 6;  
  linkedStack myList;
  start_timer();
  for(int i = 0; i < 1000000; i++){
    myList.push(A);
  }
  double cycle = elapsed_time();
  cout << "Cycles: " << cycle << endl;    
  return 0;
}
  
