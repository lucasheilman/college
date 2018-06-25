#include<iostream>
using namespace std;

/** Split a string into words
    @param s A C-style string consisting of six words
    @sc Spaces in  s  are replaced by nullbytes
    @return An array of C-style strings whose first six elements 
         are the words of  s */
char **splitWords(char *s)
{
  char **words = new char*[7];
  char **p = words;
  *p++ = s;
  while( *s != '\0' ) {
    if( ' ' == *s ) {
      *s = '\0';
      *p++ = s+1;
    }
    ++s;
  }
  return words;
}

int main()
{
  char tale[] = "It was the best of times";
  char **w = splitWords(tale);
  for (int i = 0; i<7; i++){
    cout << *w[i] << endl;
  }
  cout << w[3] << " " << w[5] << endl;
  delete [] w; 
}
