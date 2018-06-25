#include <iostream>
using namespace std;

char *append(char *a, const char*b){
  int len;
  for(len = 0; a[len] != '\0';len++){}
  int len2;
  for(len2 = 0; b[len2] !='\0'; len2++){}
  int count = 0;
  for(int i =len ;i<len+len2;i++){
    a[i]= b[count];
    count++;
  }
  return a;
}

int main(){
  char a[20] = "Hello";
  char b[10] = "world!";
  cout << "Initially, a is " << a << " and b is " << b << endl;
  cout << append(a, b) << endl;  // prints  Helloworld!
  cout << "After calling append(a,b), a is " << a << " and b is " << b << endl;
  // a should be Helloworld! and b should be unchanged
}
