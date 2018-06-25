#include<iostream>
using namespace std;

/** Reverse elements in a string
    @param s C-style string (null-terminated array of char)
    @param y holds the switched character in the string
    @return Number of (non-null) characters in s */
int stringlength(char s[])
{
  int i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}
int reverse(char str[],int len){
  int y;
  for (int x = 0; x < len/2; x++){
    y = str[len-x-1];
    str[len-x-1] = str[x];
    str[x] = y;
  }
  return 0;
}
int main()
{
  char str[20] = "supercalif";
  int len = stringlength(str);
  reverse(str,len);
  for (int x = 0; x<len; x++){
    cout << str[x];
  }
  return 0;
}
