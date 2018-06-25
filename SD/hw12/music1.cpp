// example about structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct music_t {
 string title;
 int year;
} mine, yours;
void printmusic (music_t music);
int main ()
{
 string mystr;
 mine.title = "Shake it off";
 mine.year = 2014;
 cout << "Enter title: ";
 getline (cin,yours.title);
 cout << "Enter year: ";
 getline (cin,mystr);
 stringstream(mystr) >> yours.year;
 cout << "My favorite song is:\n ";
 printmusic (mine);
 cout << "And yours is:\n ";
 printmusic (yours);
 return 0;
}
void printmusic (music_t music)
{
 cout << music.title;
 cout << " (" << music.year << ")\n";
}
