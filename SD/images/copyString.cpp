#include <iostream>
using namespace std;

/** copyString
    @param char *str1 an array of characters
    @param char *str2 an array of characters copied from str1
    @variable int length the length of str1 */
int copyString(char *&str2, const char *str1){
  int length = 0;
  while (str1[length] != '\0'){
    length++;
  }
  str2 = new char[length];
  for (int i = 0; i<length;i++){
    str2[i] = str1[i];
  }
}

int main()
{
  const char *str1 = "Hello!";
  char * str2;
  copyString(str2, str1);
  cout << "str1 is " << str1 << " and str2 is " << str2 << endl;
  return 0;
}
