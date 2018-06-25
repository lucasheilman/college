#include <iostream>
using namespace std;
#include "Car.h"
#include "Participant.h"
#include "trip.h"
#include "Song.h"
#include "Playlist.h"
#include "Event.h"
#include "Calendar.h"

int main(){
  Participant p1("Bob", "Korea",12);
  Participant p2("Rob","St. Paul",400);
  Car c1("Ford",100);
  p1.set_name("mikey");
  p2.set_destination("Northfield");
  cout << p1.get_name() << endl;
  cout << p2.get_destination() << endl;
  c1.add_participant(p1);
  c1.add_participant(p2);
  cout << c1.get_name() << endl;
  cout << p2.get_destination() << endl;
  cout << (c1.passengers[1]).get_distance() << endl;
  cout << (c1.passengers[1]).get_destination() << endl;
  c1.set_mpg(2000);
  Trip t1("Road trip", "Preter Bruritter");
  cout << t1.get_trip() << endl;
  Song s1("Don't Hurt Yourself", "Beyonce","Lemonade");
  Song s2("One Dance","Drake","Views");
  Playlist pl1("New","Lucas");
  s1.set_title("Sorry");
  cout << s1.get_title() << endl;
  cout << s2.get_artist() << endl;
  pl1.add_Song(s1);
  pl1.add_Song(s2);
  cout << pl1.get_name() << endl;
  cout << s2.get_album() << endl;
  cout << (pl1.playlist[1]).get_title() << endl;
  cout << (pl1.playlist[0]).get_artist() << endl;
  pl1.set_author("mikey");
  Event e1("Switch drivers", "Tuesday 11:00am","Minneapolis", "Switch drivers from mikey to syver");
  Event e2("Food stop","Saturday 6:00 pm","McDonalds in Lakeville","Get food at McDonalds");
  Calendar ca1("California Road Trip","Ron");
  e1.set_time("Tuesday 11:30am");
  cout << e1.get_time() << endl;
  cout << e2.get_note() << endl;
  ca1.add_Event(e1);
  ca1.add_Event(e2);
  cout << ca1.get_author() << endl;
  cout << e2.get_place() << endl;
  cout << (ca1.calendar[1]).get_title() << endl;
  cout << (ca1.calendar[0]).get_note() << endl;
  ca1.set_author("mikey");
}
