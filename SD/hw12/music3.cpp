// pointers to structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct music_t {
 string title;
 int year;
};
int main ()
{
 string mystr;
 music_t amusic;
 music_t * pmusic;
 pmusic = &amusic;
 cout << "Enter title: ";
 getline (cin, pmusic->title);
 cout << "Enter year: ";
 getline (cin, mystr);
 (stringstream) mystr >> pmusic->year;
 cout << "\nYou have entered:\n";
 cout << pmusic->title;
 cout << " (" << pmusic->year << ")\n";
 return 0;
} 
