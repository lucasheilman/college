#include <iostream>
using namespace std;

void reverse(char *str){
  char* begin = str;
  char* end = str;
  while(*end){
    ++end;
  }
  --end;
  char temp;
  while(str<end){
    temp = *str;
    *str = *end;
    str++;
    *end = temp;
    end--;
  }
  cout << begin << endl;
}

int main(){
  char str[] = "banana";
  reverse(str);
  char str2[] = "ok";
  reverse(str2);
}
