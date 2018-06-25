#include <iostream>
using namespace std;

char *append2(const char *a, const char*b){
  int len;
  for(len = 0; a[len] != '\0';len++){}
  int len2;
  for(len2 = 0; b[len2] !='\0'; len2++){}
  char *c;
  c = new char[len+len2+1];
  for(int i =0 ;i<len;i++){
    c[i]= a[i];
  }
  int count = 0; 
  for(int i =len ;i<len2+len;i++){
    c[i]= b[count];
    count++;
  }
  c[len+len2]='\0';
  return c;
}

int main(){
  cout << "*" << append2("Hello ", "world") << "*" << endl;
  // cout:   *Hello world*
}
