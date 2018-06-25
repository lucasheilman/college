#include "trip.h"
#include "Car.h"
#include "Participant.h"
#include "Calendar.h"
#include "Event.h"
#include "Playlist.h"
#include "Song.h"
#include <fstream>

#include <iostream>
using namespace std;

//Declaration of Global Variables
Trip t1("","",0); //Declaration of the New Trip
int saved=0;
char* tripfilename = new char[50];
Playlist * playlistlist = new Playlist[1000];
int playlistcount=0;
Song * songlist = new Song[1000]; 
int songcount=0;
Car * carlist = new Car[1000];
int carcount =0;
Participant * participantlist = new Participant[1000];
int participantcount = 0;
Calendar * calendarlist = new Calendar[1000];
int calendarcount = 0;
Event * eventlist = new Event[1000];
int eventcount=0;

void display_Participantlist(){ //helper function
	for (int i=0;i<participantcount;i++){
		cout << i+1 << ". " ;
		participantlist[i].display();
		cout << endl;
	}
}

void display_Songlist(){ //helper function
	for (int i=0;i<songcount;i++){
		cout << i+1 << ". " ;
		songlist[i].display();
		cout << endl;
	}
}
void remove_Participant(){ //Under SetParticipant()
	int removepartloop=0;
	while (removepartloop==0){
		cout << endl << endl;
		cout << "Choose which Participant you want to remove. " << endl;
		for (int i=0;i<participantcount;i++){
			cout << i+1 << ". " ;
			participantlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		cout << "Your choice: ";
		int choosepart;
		cin >> choosepart;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choosepart;
		}
		while(choosepart > participantcount || choosepart <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choosepart;
		}
		cin.ignore(100,'\n');
		if (choosepart == 0){ removepartloop=1;}
		else{
		  for(int i = choosepart-1;i<participantcount-1;i++){
		    participantlist[i]=participantlist[i+1];
		  }
		  participantlist[participantcount].set_name("");
		  participantlist[participantcount].set_destination("");
		  participantlist[participantcount].set_distance(0);
		  participantcount--;
		}	
	}
}


void edit_Participant(){ //Under SetParticipant()
	int editpartloop=0;
	while (editpartloop==0){
		cout << endl << endl;
		cout << "Choose which Participant you want to edit. " << endl;
		for (int i=0;i<participantcount;i++){
			cout << i+1 << ". " ;
			participantlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		cout << "Your choice: ";
		int choosepart;
		cin >> choosepart;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choosepart;
		}
		while(choosepart > participantcount || choosepart <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choosepart;
		}
		cin.ignore(100,'\n');
		if (choosepart==0){ editpartloop=1;}
	        else{
			int editpartloop2=0;
			while (editpartloop2==0){
				cout << endl << endl;
				cout << "1. Edit Participant Name" << endl;
				cout << "2. Edit Participant Destination" << endl;
				cout << "3. Edit Participant Distance" << endl;
				cout << "0. Return to previous menu" << endl << endl;
				cout << "Your choice: ";
				int loop2c;
				cin >> loop2c;
				while(cin.fail()) {
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				while(loop2c > 3 || loop2c<0){
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				cin.ignore(100,'\n');
				char * newpartname = new char[1000];
				char * newpartdestination = new char[1000];
				switch(loop2c){
					case 1:
						
						cout << "Edit Participant Name: " << endl;
						cin.getline(newpartname,1000);
						participantlist[choosepart-1].set_name(newpartname);
						delete [] newpartname;
						break;
					case 2:
						
						cout << "Edit Participant Destination: " << endl;
						cin.getline(newpartdestination,1000);
						participantlist[choosepart-1].set_destination(newpartdestination);
						break;
					case 3:
					        float newpartdistance;
						cout << "Edit Participant Distance" << endl;
						cin >> newpartdistance;
						while(cin.fail()) {
						  cout << "Please enter a float." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> newpartdistance;
						}
						cin.ignore(100,'\n');
						participantlist[choosepart-1].set_distance(newpartdistance);
						break;
					case 0:
						editpartloop2=1;
						break;
				}
			}
		}
	}
}

void add_Participant(){ //Under setParticipant()
	char* partname=new char[1000];
	char* partdest = new char[1000];
	float partdist;
	cout << endl << endl;
	cout << "Please enter the Participant's Name:" << endl;
	cin.getline(partname,1000);
	cout << "Please enter the Participant's Destination" << endl;
	cin.getline(partdest,1000);
	cout << "Please enter the Participant's Distance" << endl;
	cin >> partdist;
	while(cin.fail()) {
	  cout << "Please enter a float." << endl;
	  cin.clear();
	  cin.ignore(256,'\n');
	  cout << "Your choice: ";
	  cin >> partdist;
	}
	cin.ignore(100,'\n');
	participantlist[participantcount].set_name(partname);
	participantlist[participantcount].set_destination(partdest);
	participantlist[participantcount].set_distance(partdist);
	participantcount++;
	delete [] partname;
	delete [] partdest;
}

void setParticipant(){ //Under SetCarParticipant()
	int partloop=0;
	while (partloop==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Participants: " << endl;
		cout << "1. Add new Participant" << endl;
		cout << "2. Edit existing Participants" << endl;
		cout << "3. Remove Participant" << endl;
		cout << "0. Return to Cars and Participants Menu" << endl;
		cout << "Your Choice: " ;
		int partc;
		cin >> partc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> partc;
		}
		while(partc > 3 || partc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> partc;
		}
		cin.ignore(100,'\n');
		switch(partc){
			case 1: 
				cout << "Add new Participant" << endl;
				add_Participant();
				break;
			case 2: 
				cout << "Edit existing Participants" << endl;
				edit_Participant();
				break;
			case 3: 
				cout << "Remove Participant" << endl;
				remove_Participant();
				break;
			case 0: 
				cout << "Return to Cars and Participants Menu" << endl;
				partloop=1;
				break;

		}
	}
}

void display_Carlist(){ //helper function
	for (int i=0;i<carcount;i++){
		cout << i+1 << ". " ;
		carlist[i].display();
		cout << endl;
	}
}

void display_Playlistlist(){ //helper function
	for (int i=0;i<playlistcount;i++){
		cout << i+1 << ". " ;
		playlistlist[i].display();
		cout << endl;
	}
}
void add_Car(){//Under setCar()
	char* carname = new char[1000];
	float carmpg;
	cout << endl << endl;
	cout << "Please enter the Car Name:" << endl;
	cin.getline(carname,1000);
	carlist[carcount].set_name(carname);
	delete [] carname;
	cout << "Please enter this Car's MPG:" << endl;
	cin >> carmpg;
	while(cin.fail()) {
	  cout << "Please enter an int." << endl;
	  cin.clear();
	  cin.ignore(256,'\n');
	  cout << "Your choice: ";
	  cin >> carmpg;
	}
	cin.ignore(100,'\n');
	carlist[carcount].set_mpg(carmpg);
	int addcarloop=0;
	while(addcarloop==0){
		cout << "Please choose the Participant that you want to add to this Car." << endl;
		display_Participantlist();
		cout << "Press 0 when you are done." << endl;
		cout << "Your choice: ";
		int addcarc;
		cin >> addcarc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> addcarc;
		}
		while(addcarc > participantcount || addcarc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> addcarc;
		}
		cin.ignore(100,'\n');
		if (addcarc==0) break;
		else {
			(carlist[carcount].passengers)[carlist[carcount].get_count()]=participantlist[addcarc-1];
			carlist[carcount].set_count(carlist[carcount].get_count() + 1);
		}
	}
	carcount++;
}

void edit_Car(){ //Under setCar()
	int editcarloop=0;
	while(editcarloop==0){
		cout << endl << endl;
		cout << "Choose which Car you want to edit:" << endl;
		for (int i = 0; i<carcount;i++){
			cout << i+1 << ". " ;
			carlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		cout << "Your choice: ";
		int choice;
		cin >> choice;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choice;
		}
		while(choice > carcount || choice <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choice;
		}
		cin.ignore(100,'\n');
		if (choice==0) break;
		else{
			int editcarloop2=0;
			while (editcarloop2==0){
				cout << endl << endl;
				cout << "1. Edit Car Name" << endl;
				cout << "2. Edit Car MPG" << endl;
				cout << "3. Add Passengers" << endl;
				cout << "4. Remove Passengers" << endl;
				cout << "0. Return to previous menu" << endl<< endl;
				cout << "Your choice: ";
				int loop2c;
				cin >> loop2c;
				while(cin.fail()) {
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				while(loop2c > 4 || loop2c <0){
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				cin.ignore(100,'\n');
				char * newcarname = new char[1000];
				switch(loop2c){
					case 1:
						
						cout << "Edit Car Name: " << endl;
						cin.getline(newcarname,1000);
						carlist[choice-1].set_name(newcarname);
						delete [] newcarname;
						break;
					case 2:
						float newcarmpg;
						cout << "Edit Car MPG: " << endl;
						cin >> newcarmpg;
						while(cin.fail()) {
						  cout << "Please enter an int." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> newcarmpg;
						}
						cin.ignore(100,'\n');
						carlist[choice-1].set_mpg(newcarmpg);
						break;
					case 3: 
						cout << "Choose Participants to add:" << endl;
						display_Participantlist();
						int choice3;
						cout << "Your choice: ";
						cin >> choice3;
						while(cin.fail()) {
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice3;
						}
						while(choice3 > carlist[choice-1].get_count() || choice3 <1){
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice3;
						}
						cin.ignore(100,'\n');
						carlist[choice-1].add_participant(participantlist[choice3-1]);
						break;
					case 4: 
						cout << "Choose Participants to remove: " << endl;
						carlist[choice-1].display_participant();
						int choice4;
						cout << "Your choice: ";
						cin >> choice4;
						while(cin.fail()) {
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice4;
						}
						while(choice4 > carlist[choice-1].get_count() || choice4 <1){
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice4;
						}
						cin.ignore(100,'\n');
						for(int i = choice4-1;i < (carlist[choice-1].get_count());i++){
						  carlist[choice-1].passengers[i]=carlist[choice-1].passengers[i+1];
						}
						carlist[choice-1].set_count(carlist[choice-1].get_count()-1);
						
						break;
					case 0:
						editcarloop2=1;
						break;
				}
			}
		}
	} 
}

void remove_Car(){ //Under setCar()
	int removecarloop=0;
	while (removecarloop==0){
		cout << "Choose which Car you would like to remove." << endl;
		display_Carlist();
		int removecar;
		cout << "Or 0 to return to the previous menu."<<endl;
		cout << "Your Choice: " << endl;
		cin >> removecar;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> removecar;
		}
		while(removecar > carcount || removecar <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> removecar;
		}
		cin.ignore(100,'\n');
		if (removecar == 0){ removecarloop=1;}
		else{
		  for(int i = removecar;i<carcount;i++){
		    carlist[removecar-1]=carlist[removecar];
		  }
		  carcount--;
		  delete [] carlist[removecar-1].passengers;
		  carlist[removecar-1].passengers = new Participant [100];
		}
	}
}


void setCar(){ //Under SetCarParticipant()
	int carloop=0;
	while(carloop==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Cars" << endl;
		cout << "1. Add new Car" << endl;
		cout << "2. Edit existing Cars" << endl;
		cout << "3. Remove Car" << endl;
		cout << "0. Return to Cars and Participants Menu" << endl;
		cout << "Your Choice: " ;
		int carc;
		cin >> carc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> carc;
		}
		while(carc > 3 || carc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> carc;
		}
		cin.ignore(100,'\n');
		switch(carc){
			case 1:
				cout << "Add new Car" << endl; //done
				add_Car();
				break;
			case 2:
				cout << "Edit existing Cars" << endl; //done
				edit_Car();
				break;
			case 3:
				cout << "Remove Car" << endl; //done
				remove_Car();
				break;
			case 0:
				cout << "Return to Cars and Participants Menu" << endl;
				carloop=1;
				break;
		}
	}
}

void SetCarParticipant(){ //Under MainMenu()
	int carpartloop = 0;
	while (carpartloop==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Cars and Participants" << endl;
		cout << "1. Manage Participants" << endl; 
		cout << "2. Manage Cars" << endl;
		cout << "0. Return to Main Menu" << endl;
		cout << "Your Choice:" ;
		int carpartc; //new choice
		cin >> carpartc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> carpartc;
		}
		while(carpartc > 2 || carpartc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> carpartc;
		}
		cin.ignore(100,'\n');
		switch (carpartc){
			case 1: 
				cout << "Manage Participants" << endl; //done
				setParticipant();
				break;
			case 2: 
				cout << "Manage Cars" << endl; //done
				setCar();
				break;
			case 0: 
				cout << "Return to Main Menu" << endl;
				carpartloop = 1;
				break;
		}
	}
}

void edit_Song(){ //Under SetSong()
	int editsongloop=0;
	while (editsongloop==0){
		cout << endl << endl;
		cout << "Choose which Song you want to edit: " << endl;
		for (int i=0;i<songcount;i++){
			cout << i+1 << ". " ;
			songlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		cout << "Your choice: ";
		int choosesong;
		cin >> choosesong;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choosesong;
		}
		while(choosesong > songcount || choosesong <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choosesong;
		}
		cin.ignore(100,'\n');
		if (choosesong==0){ editsongloop=1;}
	    else{
			int editsongloop2=0;
			while (editsongloop2==0){
				cout << endl << endl;
				cout << "1. Edit Song Title" << endl;
				cout << "2. Edit Song Album" << endl;
				cout << "3. Edit Song Artist" << endl;
				cout << "0. Return to previous menu" << endl << endl;
				cout << "Your choice: ";
				int loop2c;
				cin >> loop2c;
				while(cin.fail()) {
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				while(loop2c > 3 || loop2c <0){
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				cin.ignore(100,'\n');
				char * newsongtitle = new char[1000];
				char * newsongalbum = new char[1000];
				char * newsongartist = new char[1000];
				switch(loop2c){
					case 1:
						
						cout << "Edit Song Title:" << endl;
						cin.getline(newsongtitle,1000);
						songlist[choosesong-1].set_title(newsongtitle);
						delete [] newsongtitle;
						break;
					case 2:
						cout << "Edit Song Album:" << endl;
						cin.getline(newsongalbum,1000);
						songlist[choosesong-1].set_album(newsongalbum);
						break;
					case 3:
						cout << "Edit Song Artist:" << endl;
						cin.getline(newsongartist,1000);
						songlist[choosesong-1].set_artist(newsongartist);
						break;
					case 0:
						editsongloop2=1;
						break;
				}
			}
		}
	}
}

void remove_Song(){ //Under SetSong()
	int removesongloop=0;
	while (removesongloop==0){
		cout << endl << endl;
		cout << "Choose which Song you want to remove: " << endl;
		for (int i=0;i<songcount;i++){
			cout << i+1 << ". " ;
			songlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		cout << "Your choice: ";
		int choosesong;
		cin >> choosesong;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choosesong;
		}
		while(choosesong > songcount || choosesong <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choosesong;
		}
		cin.ignore(100,'\n');
		if (choosesong == 0){ removesongloop=1;}
		else{
		  for(int i = choosesong-1;i<songcount-1;i++){
		    songlist[i]=songlist[i+1];
		  }
		  songlist[songcount].set_title("");
		  songlist[songcount].set_album("");
		  songlist[songcount].set_artist("");
		  songcount--;
		}	
	}
}


void add_Song(){ //Under setSong()
	char* songtitle=new char[1000];
	char* songalbum = new char[1000];
	char* songartist = new char[1000];
	cout << endl << endl;
	cout << "Please enter the Song's Title:" << endl;
	cin.getline(songtitle,1000);
	cout << "Please enter the Songs's Album:" << endl;
	cin.getline(songalbum,1000);
	cout << "Please enter the Song's Artist:" << endl;
	cin.getline(songartist,1000);
	songlist[songcount].set_title(songtitle);
	songlist[songcount].set_album(songalbum);
	songlist[songcount].set_artist(songartist);
	songcount++;
	delete [] songtitle;
	delete [] songalbum;
	delete [] songartist;
}

void setSong(){ //Under SetPlaylistSong()
	int songloop=0;
	while (songloop==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Songs." << endl;
		cout << "1. Add new Song" << endl;
		cout << "2. Edit existing Songs" << endl;
		cout << "3. Remove Songs" << endl;
		cout << "0. Return to Playlists and Songs Menu" << endl;
		cout << "Your Choice: " ;
		int songc;
		cin >> songc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> songc;
		}
		while(songc > 3 || songc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> songc;
		}
		cin.ignore(100,'\n');
		switch(songc){
			case 1: 
				cout << "Add new Song" << endl;
				add_Song();
				break;
			case 2: 
				cout << "Edit existing Songs" << endl;
				edit_Song();
				break;
			case 3: 
				cout << "Remove Song" << endl;
				remove_Song();
				break;
			case 0: 
				cout << "Return to Playlists and Songs Menu" << endl;
				songloop=1;
				break;

		}
	}
}

void add_Playlist(){//Under setPlaylist()
	char* playlistname = new char[1000];
	char* playlistauthor = new char[1000];
	cout << endl << endl;
	cout << "Please enter the Playlist's Name:" << endl;
	cin.getline(playlistname,1000);
	playlistlist[playlistcount].set_name(playlistname);
	delete [] playlistname;
	cout << "Please enter the Playlist's Author:" << endl;
	cin.getline(playlistauthor,1000);
	playlistlist[playlistcount].set_author(playlistauthor);
	int addplayloop=0;
	while(addplayloop==0){
		cout << "Please choose the Songs that you want to add to this Playlist." << endl;
		display_Songlist();
		cout << "Press 0 when you are done." << endl;
		cout << "Your choice: ";
		int addplayc;
		cin >> addplayc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> addplayc;
		}
		while(addplayc > songcount || addplayc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> addplayc;
		}
		cin.ignore(100,'\n');
		if (addplayc==0) break;
		else {
		  (playlistlist[playlistcount].playlist)[playlistlist[playlistcount].get_count()]=songlist[addplayc-1];
			playlistlist[playlistcount].set_count(playlistlist[playlistcount].get_count() + 1);
		}
	}
	playlistcount++;
}

void edit_Playlist(){ //Under setPlaylist()
	int editplayloop=0;
	while(editplayloop==0){
		cout << endl << endl;
		cout << "Choose which Playlist you want to edit:" << endl;
		for (int i = 0; i<playlistcount;i++){
			cout << i+1 << ". " ;
			playlistlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		cout << "Your choice: ";
		int choice;
		cin >> choice;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choice;
		}
		while(choice > playlistcount || choice <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choice;
		}
		cin.ignore(100,'\n');
		if (choice==0) break;
		else{
			int editplayloop2=0;
			while (editplayloop2==0){
				cout << endl << endl;
				cout << "1. Edit Playlist Name" << endl;
				cout << "2. Edit Playlist Author" << endl;
				cout << "3. Add Songs" << endl;
				cout << "4. Remove Songs" << endl;
				cout << "0. Return to previous menu" << endl<< endl;
				cout << "Your choice: ";
				int loop2c;
				cin >> loop2c;
				while(cin.fail()) {
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				while(loop2c > 4 || loop2c <0){
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				cin.ignore(100,'\n');
				char * newplaylistname = new char[1000];
				char * newplaylistauthor = new char[1000];
				switch(loop2c){
					case 1:
						
						cout << "Edit Playlist Name:" << endl;
						cin.getline(newplaylistname,1000);
						playlistlist[choice-1].set_name(newplaylistname);
						delete [] newplaylistname;
						break;
				        case 2:
						cout << "Edit Playlist Author:" << endl;
						cin.getline(newplaylistauthor,1000);
						playlistlist[choice-1].set_author(newplaylistauthor);
						break;
					case 3: 
						cout << "Choose Song to add:" << endl;
						display_Songlist();
						cout << "Your choice: ";
						int choice3;
						cin >> choice3;
						while(cin.fail()) {
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice3;
						}
						while(choice3 > playlistlist[choice-1].get_count() || choice3 <1){
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice3;
						}
						cin.ignore(100,'\n');
					        playlistlist[choice-1].add_song(songlist[choice3-1]);
						break;
					case 4: 
						cout << "Choose Song to remove: " << endl;
						playlistlist[choice-1].display_song();
						cout << "Your choice: ";
						int choice4;
						cin >> choice4;
						while(cin.fail()) {
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice4;
						}
						while(choice4 > playlistlist[choice-1].get_count() || choice4 <1){
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice4;
						}
						cin.ignore(100,'\n');
					        for(int i = choice4-1;i < (playlistlist[choice-1].get_count());i++){
						  playlistlist[choice-1].playlist[i]=playlistlist[choice-1].playlist[i+1];
						}
						playlistlist[choice-1].set_count(playlistlist[choice-1].get_count()-1);
					case 0:
						editplayloop2=1;
						break;
				}
			}
		}
	} 
}

void remove_Playlist(){ //Under setPlaylist()
	int removeplayloop=0;
	while (removeplayloop==0){
		cout << "Choose which Playlist you would like to remove:" << endl;
		display_Playlistlist();
		int removeplay;
		cout << "Or 0 to return to the previous menu"<<endl;
		cin >> removeplay;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> removeplay;
		}
		while(removeplay > playlistcount || removeplay <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> removeplay;
		}
		cin.ignore(100,'\n');
		if (removeplay == 0){ removeplayloop=1;}
		else{
		  for(int i = removeplay;i<playlistcount;i++){
		    playlistlist[removeplay-1]=playlistlist[removeplay];
		  }
		  playlistcount--;
		  delete [] playlistlist[removeplay-1].playlist;
		  playlistlist[removeplay-1].playlist = new Song [100];
		}
	}
}


void setPlaylist(){ //Under SetPlaylistSong()
	int playloop=0;
	while(playloop==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Playlists " << endl;
		cout << "1. Add new Playlist" << endl;
		cout << "2. Edit existing Playlists" << endl;
		cout << "3. Remove Playlist" << endl;
		cout << "0. Return to Playlists and Songs Menu" << endl;
		cout << "Your Choice: " ;
		int playc;
		cin >> playc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> playc;
		}
		while(playc > 3 || playc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> playc;
		}
		cin.ignore(100,'\n');
		switch(playc){
			case 1:
				cout << "Add new Playlist" << endl; //done
				add_Playlist();
				break;
			case 2:
				cout << "Edit existing Playlists" << endl; //done
				edit_Playlist();
				break;
			case 3:
				cout << "Remove Playlist" << endl; //done
				remove_Playlist();
				break;
			case 0:
				cout << "Return to Playlists and Songs Menu" << endl;
				playloop=1;
				break;
		}
	}
}


void SetPlaylistSong(){ //Under MainMenu()
	int carplaysong = 0;
	while (carplaysong==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Playlists and Songs" << endl;
		cout << "1. Manage Songs" << endl;
		cout << "2. Manage Playlists" << endl;
		cout << "0. Return to Main Menu" << endl;
		cout << "Your Choice:" ;
		int playsongc; //new choice
		cin >> playsongc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> playsongc;
		}
		while(playsongc > 2 || playsongc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> playsongc;
		}
		cin.ignore(100,'\n');
		switch (playsongc){
			case 1: 
				cout << "Manage Songs" << endl;
				setSong();
				break;
			case 2: 
				cout << "Manage Playlists" << endl;
				setPlaylist();
				break;
			case 0: 
				cout << "Return to Main Menu" << endl;
				carplaysong = 1;
				break;
		}
	}
}



void display_Eventlist(){ //helper function
	for (int i=0;i<eventcount;i++){
		cout << i+1 << ". " ;
		eventlist[i].display();
		cout << endl;
	}
}

void remove_Event(){ //Under SetEvent()
	int removeeventloop=0;
	while (removeeventloop==0){
		cout << endl << endl;
		cout << "Choose which Event you want to remove: " << endl;
		for (int i=0;i<eventcount;i++){
			cout << i+1 << ". " ;
		        eventlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		int chooseevent;
		cin >> chooseevent;
	        while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> chooseevent;
		}
		while(chooseevent > eventcount || chooseevent <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> chooseevent;
		}
		cin.ignore(100,'\n');
		if (chooseevent == 0){ removeeventloop=1;}
		else{
		  for(int i = chooseevent-1;i<eventcount-1;i++){
		    eventlist[i]=eventlist[i+1];
		  }
		  eventcount--;
		}	
	}
}


void edit_Event(){ //Under SetEvent()
	int editeventloop=0;
	while (editeventloop==0){
		cout << endl << endl;
		cout << "Choose which Event you want to edit: " << endl;
		for (int i=0;i<eventcount;i++){
			cout << i+1 << ". " ;
		        eventlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		cout << "Your choice: ";
		int chooseevent;
		cin >> chooseevent;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> chooseevent;
		}
		while(chooseevent > eventcount || chooseevent <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> chooseevent;
		}
		cin.ignore(100,'\n');
		if (chooseevent==0){ editeventloop=1;}
	        else{
			int editeventloop2=0;
			while (editeventloop2==0){
				cout << endl << endl;
				cout << "1. Edit Event Title" << endl;
				cout << "2. Edit Event Date and Time" << endl;
				cout << "3. Edit Event Place" << endl;
				cout << "4. Edit Event Note" << endl;
				cout << "0. Return to previous menu" << endl << endl;
				cout << "Your choice: ";
				int loop2c;
				cin >> loop2c;
				while(cin.fail()) {
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				while(loop2c > 4 || loop2c <0){
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				cin.ignore(100,'\n');
				char * neweventtitle = new char[1000];
				char * neweventtime = new char[1000];
				char * neweventplace = new char[1000];
				char * neweventnote = new char[1000];
				switch(loop2c){
					case 1:
						
						cout << "Edit Event Title:" << endl;
						cin.getline(neweventtitle,1000);
						eventlist[chooseevent-1].set_title(neweventtitle);
						delete [] neweventtitle;
						break;
					case 2:
						
						cout << "Edit Event Date and Time in the form MM/DD/YY 12:00pm:" << endl;
						cin.getline(neweventtime,1000);
					        eventlist[chooseevent-1].set_time(neweventtime);
						break;
					case 3:
						cout << "Edit Event Place: " << endl;
						cin.getline(neweventplace,1000);
					        eventlist[chooseevent-1].set_place(neweventplace);
						break;
					case 4:
						cout << "Edit Event Note: " << endl;
						cin.getline(neweventnote,1000);
					        eventlist[chooseevent-1].set_note(neweventnote);
						break;
					case 0:
						editeventloop2=1;
						break;
				}
			}
		}
	}
}

void add_Event(){ //Under setEvent()
        char* eventtitle=new char[1000];
	char* eventtime = new char[1000];
	char* eventplace = new char[1000];
	char* eventnote = new char[1000];
	cout << endl << endl;
	cout << "Please enter the Event's Title:" << endl;
	cin.getline(eventtitle,1000);
	cout << "Please enter the Event's Date and Time in the form MM/DD/YY 12:00pm:" << endl;
	cin.getline(eventtime,1000);
	cout << "Please enter the Event's Place:" << endl;
	cin.getline(eventplace,1000);
	cout << "Please enter the Event's Note:" << endl;
	cin.getline(eventnote,1000);
	eventlist[eventcount].set_title(eventtitle);
	eventlist[eventcount].set_time(eventtime);
	eventlist[eventcount].set_place(eventplace);
	eventlist[eventcount].set_note(eventnote);
	eventlist[eventcount].findtimestamp(eventtime);
	eventcount++;
	delete [] eventtitle;
	delete [] eventtime;
	delete [] eventplace;
	delete [] eventnote;
}

void setEvent(){ //Under SetCalEvent()
	int eventloop=0;
	while (eventloop==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Events " << endl;
		cout << "1. Add new Event" << endl;
		cout << "2. Edit existing Events" << endl;
		cout << "3. Remove Event" << endl;
		cout << "0. Return to Calendar and Event Menu" << endl;
		cout << "Your Choice: " ;
		int eventc;
		cin >> eventc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> eventc;
		}
		while(eventc > 3 || eventc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> eventc;
		}
		cin.ignore(100,'\n');
		switch(eventc){
			case 1: 
				cout << "Add new Event" << endl;
				add_Event();
				break;
			case 2: 
				cout << "Edit existing Event" << endl;
				edit_Event();
				break;
			case 3: 
				cout << "Remove Event" << endl;
				remove_Event();
				break;
			case 0: 
				cout << "Return to Calendars and Events Menu" << endl;
				eventloop=1;
				break;

		}
	}
}

void display_Calendarlist(){ //helper function
	for (int i=0;i<calendarcount;i++){
		cout << i+1 << ". " ;
		calendarlist[i].display();
		cout << endl;
	}
}

void add_Calendar(){//Under setCalendar()
	char* calendarname = new char[1000];
	char* calendarauthor = new char[1000];
	cout << endl << endl;
	cout << "Please enter this Calendar's Name:" << endl;
	cin.getline(calendarname,1000);
	calendarlist[calendarcount].set_name(calendarname);
	delete [] calendarname;
	cout << "Please enter this Calendar's Author" << endl;
	cin.getline(calendarauthor,1000);
	calendarlist[calendarcount].set_author(calendarauthor);
	int addcalloop=0;
	while(addcalloop==0){
		cout << "Please choose the Events that you want to add to this Calendar." << endl;
		display_Eventlist();
		cout << "Press 0 when you are done." << endl;
		cout <<"Your choice: ";
		int addcalc;
		cin >> addcalc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> addcalc;
		}
		while(addcalc > eventcount || addcalc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> addcalc;
		}
		cin.ignore(100,'\n');
		if (addcalc==0) break;
		else {
			(calendarlist[calendarcount].calendar)[calendarlist[calendarcount].get_count()]=eventlist[addcalc-1];
			calendarlist[calendarcount].set_count(calendarlist[calendarcount].get_count() + 1);
			calendarlist[calendarcount].organize();
		}
	}
	calendarcount++;
}



void edit_Calendar(){ //Under setCalendar()
	int editcalloop=0;
	while(editcalloop==0){
		cout << endl << endl;
		cout << "Choose which Calendar you want to edit:" << endl;
		for (int i = 0; i<calendarcount;i++){
			cout << i+1 << ". " ;
			calendarlist[i].display();
			cout << endl;
		}
		cout << endl;
		cout << "Or enter 0 to return to previous menu." << endl;
		cout << "Your choice: ";
		int choice;
		cin >> choice;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choice;
		}
		while(choice > calendarcount || choice <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> choice;
		}
		cin.ignore(100,'\n');
		if (choice==0) break;
		else{
			int editcalloop2=0;
			while (editcalloop2==0){
				cout << endl << endl;
				cout << "1. Edit Calendar Name" << endl;
				cout << "2. Edit Calendar Author" << endl;
				cout << "3. Add Events" << endl;
				cout << "4. Remove Events" << endl;
				cout << "0. Return to previous menu" << endl<< endl;
				cout << "Your choice: ";
				int loop2c;
				cin >> loop2c;
				while(cin.fail()) {
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				while(loop2c > 4 || loop2c <0){
				  cout << "Please enter a listed choice." << endl;
				  cin.clear();
				  cin.ignore(256,'\n');
				  cout << "Your choice: ";
				  cin >> loop2c;
				}
				cin.ignore(100,'\n');
				char * newcalname = new char[1000];
				char * newcalauthor = new char[1000];
				switch(loop2c){
					case 1:
						
						cout << "Edit Calendar Name: " << endl;
						cin.getline(newcalname,1000);
						calendarlist[choice-1].set_name(newcalname);
						delete [] newcalname;
						break;
					case 2:
						cout << "Edit Calendar Author: " << endl;
						cin.getline(newcalauthor,1000);
						calendarlist[choice-1].set_author(newcalauthor);
						break;
					case 3: 
						cout << "Choose Events to add:" << endl;
						display_Eventlist();
						cout << "Your Choice: ";
						int choice3;
						cin >> choice3;
						while(cin.fail()) {
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice3;
						}
						while(choice3 > calendarlist[choice-1].get_count() || choice3 <1){
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice3;
						}
						cin.ignore(100,'\n');
						calendarlist[choice-1].add_Event(eventlist[choice3-1]);
						(calendarlist[choice-1]).organize();
						break;
					case 4: 
					        cout << "Choose Events to remove: " << endl;
						calendarlist[choice-1].display_event();
						cout << "Your choice: ";
						int choice4;
						cin >> choice4;
						while(cin.fail()) {
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice4;
						}
						while(choice4 > calendarlist[choice-1].get_count() || choice4 <1){
						  cout << "Please enter a listed choice." << endl;
						  cin.clear();
						  cin.ignore(256,'\n');
						  cout << "Your choice: ";
						  cin >> choice4;
						}
						cin.ignore(100,'\n');
						for(int i = choice4-1;i < (calendarlist[choice-1].get_count());i++){
						  calendarlist[choice-1].calendar[i]=calendarlist[choice-1].calendar[i+1];
						}
						calendarlist[choice-1].set_count(calendarlist[choice-1].get_count()-1);
						break;
					case 0:
						editcalloop2=1;
						break;
				}
			}
		}
	} 
}

void remove_Calendar(){ //Under setCalendar()
	int removecalloop=0;
	while (removecalloop==0){
		cout << "Choose which Calendar you would like to remove." << endl;
		display_Calendarlist();
		int removecal;
		cout << "Or 0 to return to the previous menu."<<endl;
		cout << "Your choice: ";
		cin >> removecal;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> removecal;
		}
		while(removecal >calendarcount || removecal <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> removecal;
		}
		cin.ignore(100,'\n');
		if (removecal == 0){ removecalloop=1;}
		else{
		  for(int i = removecal;i<calendarcount;i++){
		    calendarlist[removecal-1]=calendarlist[removecal];
		  }
		  calendarcount--;
		  delete [] calendarlist[removecal-1].calendar;
		  calendarlist[removecal-1].calendar = new Event [100];
		}
	}
}


void setCalendar(){ //Under SetCalendarEvent()
	int calloop=0;
	while(calloop==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Calendars." << endl;
		cout << "1. Add new Calendar" << endl;
		cout << "2. Edit existing Calendars" << endl;
		cout << "3. Remove Calendar" << endl;
		cout << "0. Return to Calendar and Events Menu" << endl;
		cout << "Your choice: ";
		int calc;
		cin >> calc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> calc;
		}
		while(calc >3 || calc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> calc;
		}
		cin.ignore(100,'\n');
		switch(calc){
			case 1:
				cout << "Add new Calendar" << endl; //done
				add_Calendar();
				break;
			case 2:
				cout << "Edit existing Calendars" << endl; //done
				edit_Calendar();
				break;
			case 3:
				cout << "Remove Calendar" << endl; //done
				remove_Calendar();
				break;
			case 0:
				cout << "Return to Calendars and Events Menu" << endl;
				calloop=1;
				break;
		}
	}
}

void SetCalEvent(){ //Under MainMenu()
	int calevent = 0;
	while (calevent==0){
		cout << endl << endl;
		cout << "Please choose what you would like to do with Calendars and Events." << endl;
		cout << "1. Manage Calendars" << endl;
		cout << "2. Manage Events" << endl;
		cout << "0. Return to Main Menu" << endl;
		cout << "Your Choice: " ;
		int caleventc; //new choice
		cin >> caleventc;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> caleventc;
		}
		while(caleventc >2 || caleventc <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> caleventc;
		}
		cin.ignore(100,'\n');
		switch (caleventc){
			case 1: 
				cout << "Manage Calendars" << endl;
				setCalendar();
				break;
			case 2: 
				cout << "Manage Events" << endl;
				setEvent();
				break;
			case 0: 
				cout << "Return to Main Menu" << endl;
				calevent = 1;
				break;
		}
	}
}

void edit_Trip(){
	int edittriploop=0;
	while (edittriploop==0){
	  cout << endl << endl;
	  cout << "1. Edit Trip Name" << endl;
	  cout << "2. Edit Trip Author" << endl;
	  cout << "3. Edit Trip Cost of Gas per gallon" << endl;
	  cout << "0. Return to previous menu" << endl << endl;
	  cout << "Your choice: ";
	  int loop2c;
	  cin >> loop2c;
	  while(cin.fail()) {
	    cout << "Please enter a listed choice." << endl;
	    cin.clear();
	    cin.ignore(256,'\n');
	    cout << "Your choice: ";
	    cin >> loop2c;
	  }
	  while(loop2c >3 || loop2c <0){
	    cout << "Please enter a listed choice." << endl;
	    cin.clear();
	    cin.ignore(256,'\n');
	    cout << "Your choice: ";
	    cin >> loop2c;
	  }
	  cin.ignore(100,'\n');
	  char * newtripname = new char[1000];
	  char * newtripauthor = new char[1000];
	  switch(loop2c){
	  case 1:
						
	    cout << "Edit Trip Name:" << endl;
	    cin.getline(newtripname,1000);
	    t1.set_trip(newtripname);
	    delete [] newtripname;
	    break;
	  case 2:					
	    cout << "Edit Trip Author:" << endl;
	    cin.getline(newtripauthor,1000);
	    t1.set_author(newtripauthor);
	    break;
	  case 3:
	    float newgascost;
	    cout << "Edit Cost of Gas per gallon: " << endl;
	    cin >> newgascost;
	    while(cin.fail()) {
	      cout << "Please enter a float." << endl;
	      cin.clear();
	      cin.ignore(256,'\n');
	      cout << "Your choice: ";
	      cin >> newgascost;
	    }
	    cin.ignore(100,'\n');
	    t1.set_gas(newgascost);
	    break;
	  case 0:
	    edittriploop=1;
	    break;
	  }
	}
}

void RoadTripExport(){ //Under MainMenu(), saves to .txt file
	char * txttitle = new char[100];
	cout << "File name (please type .txt at the end): " << endl;
	cin >> txttitle ;
	ofstream f(txttitle);

	f << "Trip Name: " << t1.get_trip() << endl;
	f << "Author: " << t1.get_author() << endl << endl;

	f << "Playlist: " << endl;
	for (int i=0;i<playlistcount;i++){
		f << "Playlist Name" << i+1 << ": " << playlistlist[i].get_name() << "/ Playlist author: " << playlistlist[i].get_author() << "/ Songs: " << endl;
	  	for (int j=0;j<playlistlist[j].get_count();j++){
	    	f << j+1 << ". " << (playlistlist[i].playlist[j]).get_title() << "/" << (playlistlist[i].playlist[j]).get_artist() << "/" << (playlistlist[i].playlist[j]).get_album() << endl;
	  	}
	} 
	f << endl;
	f << "Songs: " << endl;
	for (int i=0;i<songcount;i++){
		f << i+1 << ": " << songlist[i].get_title() << "/" << songlist[i].get_artist() << "/" << songlist[i].get_album() << endl;
	}

	f << endl;
	f << "Cars: " << endl;
	for (int i=0;i<carcount;i++){
		f << i+1 << ": " << "Car name: " << carlist[i].get_name() << ", mpg: " << carlist[i].get_mpg() << ", passengers: " << endl;
		for (int j=0;j<carlist[i].get_count();j++){
		  f << "Participant Name: " << (carlist[i].passengers[j]).get_name() << ", Destination: " << (carlist[i].passengers[j]).get_destination() << ", Distance: " << (carlist[i].passengers[j]).get_distance() << ", Gas money owed: " << (carlist[i].passengers[j]).get_gasmoney(t1.get_gas(),carlist[i].get_count(),carlist[i].get_mpg()) << endl;
		}
	}

	f << endl;
	f << "Participants: " << endl;
	for (int i=0;i<participantcount;i++){
	  f << i+1 << ": " << "Participant Name: " << participantlist[i].get_name() << ", Destination: " << participantlist[i].get_destination() << ", Distance: " << participantlist[i].get_distance() << endl;
	}

	f << endl;
	f << "Calendar: " << endl;
	for (int i=0; i<calendarcount;i++){
		f << i+1 << ": " << "Calendar Name: " << calendarlist[i].get_name() << ", Author: " << calendarlist[i].get_author() << ", Events: " << endl;
		for (int j=0;j<calendarlist[i].get_count();j++){
			f << j+1 << ": " << "Event Name: " << (calendarlist[i].calendar[j]).get_title() << ", Time: " << (calendarlist[i].calendar[j]).get_time() << ", Place: " << (calendarlist[i].calendar[j]).get_place() << ", Note: " << (calendarlist[i].calendar[j]).get_note() << endl;
		}
	}

	f << endl;
	f << "Events: " << endl;
	for (int i=0;i<eventcount;i++){
		f << i+1 << ": " << "Event Name: " << eventlist[i].get_title() << ", Time " << eventlist[i].get_time() << ", Place: " << eventlist[i].get_place() << ", Note: " << eventlist[i].get_note() << endl;
	}
}

void RoadTripSave(){
	ofstream f(tripfilename);
	f << t1.get_trip() << endl << t1.get_author() << endl << t1.get_gas() << endl;
	//Details of Participants
	f << participantcount << endl;
	for (int i=0;i<participantcount;i++){
		f << participantlist[i].get_name() << endl << participantlist[i].get_destination() << endl << participantlist[i].get_distance() << endl;
	}
	//Details of Car
	f << carcount << " " << endl;
	for (int i=0;i<carcount;i++){
		f << carlist[i].get_name() << endl << carlist[i].get_mpg() << endl << carlist[i].get_count() << endl;
		for (int j=0;j<carlist[i].get_count();j++){
			f << (carlist[i].passengers[j]).get_name() << endl << (carlist[i].passengers[j]).get_destination() << endl << (carlist[i].passengers[j]).get_distance() << endl;
		}
	}
	//Details of Songs
	f << songcount << endl;
	for (int i=0;i<songcount;i++){
		f << songlist[i].get_title() << endl << songlist[i].get_artist() << endl << songlist[i].get_album() << endl;
	}
	//Details of Playlist
	f << playlistcount << endl;
	for (int i=0;i<playlistcount;i++){
		f << playlistlist[i].get_name() << endl << playlistlist[i].get_author() << endl << playlistlist[i].get_count() << endl;
		for (int j =0;j<playlistlist[i].get_count();j++){
			f << (playlistlist[i].playlist[j]).get_title() << endl << (playlistlist[i].playlist[j]).get_artist() << endl << (playlistlist[i].playlist[j]).get_album() << endl;
		}
	}

	//Details of Event
	f << eventcount << endl;
	for (int i=0;i<eventcount;i++){
		f << eventlist[i].get_title() << endl << eventlist[i].get_place() << endl << eventlist[i].get_time() << endl << eventlist[i].get_note() << endl;
	}

	//Details of Calendar 
	f << calendarcount << endl;
	for (int i=0;i<calendarcount;i++){
		f << calendarlist[i].get_name() << endl << calendarlist[i].get_author() << endl << calendarlist[i].get_count() << endl;
		for (int j =0;j<calendarlist[i].get_count();j++){
			f << (calendarlist[i].calendar[j]).get_title() << endl << (calendarlist[i].calendar[j]).get_place() << endl << (calendarlist[i].calendar[j]).get_time() << endl << (calendarlist[i].calendar[j]).get_note() <<  endl;
		}
	}
}

void RoadTripSaveAs(){
	cout << "File name (Please type in .trip): " << endl;
	cin >> tripfilename;
	cin.ignore(256,'\n'); 
	RoadTripSave();
}

void RoadTripImport(){
	cout << "Type in the .trip file to be loaded" << endl;
	cin >> tripfilename;
	cin.ignore(256,'\n'); 
	cout << tripfilename << endl;
	ifstream f;
	f.open(tripfilename);
    char* tripname = new char[1000];
	char* authorname = new char [1000];
	float gasimp;
	f.getline(tripname,1000);
	t1.set_trip(tripname);
	f.getline(authorname,1000);
	t1.set_author(authorname);
	f >> gasimp;
	f.ignore(256,'\n');
	t1.set_gas(gasimp);
	delete[] tripname;
	delete[] authorname;
	
	//Import Participants
	f >> participantcount;
	f.ignore(256,'\n');
	for (int i=0;i<participantcount;i++){
		char* parstr1 = new char[100];
		char* parstr2 = new char[100];
		float parstr3;
		f.getline(parstr1,1000);
		f.getline(parstr2,1000);
		f >> parstr3;
		f.ignore(256,'\n');
		participantlist[i].set_name(parstr1);
		participantlist[i].set_destination(parstr2);
		participantlist[i].set_distance(parstr3);
		delete [] parstr1;
		delete [] parstr2;
	}

	//Import Cars
	f >> carcount;
	f.ignore(256,'\n');
	for (int i=0;i<carcount;i++){
		char* carstr1 = new char[100];
		float carstr2;
		int carstr3;
		f.getline(carstr1, 100);
		f >> carstr2;
		f.ignore(256,'\n');
		f >> carstr3;
		f.ignore(256,'\n');
		carlist[i].set_name(carstr1);
		carlist[i].set_mpg(carstr2);
		carlist[i].set_count(carstr3);
		carlist[i].passengers = new Participant[100];
		for (int j=0;j<carstr3;j++){
			char* parstr1 = new char[100];
			char* parstr2 = new char[100];
			float parstr3;
			f.getline(parstr1,1000);
			f.getline(parstr2,1000);
			f >> parstr3;
			f.ignore(256,'\n');
			(carlist[i].passengers)[j].set_name(parstr1);
			(carlist[i].passengers)[j].set_destination(parstr2);
			(carlist[i].passengers)[j].set_distance(parstr3);
			delete [] parstr1;
			delete [] parstr2;
		}
		delete[] carstr1;
	}
	//Import Songs
	f >> songcount;
	f.ignore(256,'\n');
	for (int i=0;i<songcount;i++){
		char* songtitle = new char[100];
		char* songartist = new char[100];
		char* songalbum = new char[100];
		f.getline(songtitle,100);
		f.getline(songartist,100);
		f.getline(songalbum,100);
		songlist[i].set_title(songtitle);
		songlist[i].set_artist(songartist);
		songlist[i].set_album(songalbum);
		delete [] songtitle;
		delete[] songartist;
		delete[] songalbum;
	}

	//Import Playlist
	f >> playlistcount;
	f.ignore(256,'\n');
	for (int i=0;i<playlistcount;i++){
		char* playname = new char[100];
		char* playauthor = new char[100];
		int playcount;
		f.getline(playname,100);
		f.getline(playauthor,100);
		f >> playcount;
		f.ignore(256,'\n');
		playlistlist[i].set_name(playname);
		playlistlist[i].set_author(playauthor);
		playlistlist[i].set_count(playcount);
		playlistlist[i].playlist = new Song [1000];
		for (int j=0;j<playcount;j++){
			char* songtitle = new char[100];
			char* songartist = new char[100];
			char* songalbum = new char[100];
			f.getline(songtitle,100);
			f.getline(songartist,100);
			f.getline(songalbum,100);
			(playlistlist[i].playlist)[j].set_title(songtitle);
			(playlistlist[i].playlist)[j].set_artist(songartist);
			(playlistlist[i].playlist)[j].set_album(songalbum);
			delete [] songtitle;
			delete[] songartist;
			delete[] songalbum;
		}
		delete [] playname;
		delete [] playauthor;
	}

	//Import Events
	f >> eventcount;
	f.ignore(256,'\n');
	for (int i=0;i<eventcount;i++){
		char * evetitle = new char [100];
		char * eveplace = new char [100];
		char * evetime = new char [100];
		char * evenote = new char [100];
		f.getline(evetitle,100);
		f.getline(eveplace,100);
		f.getline(evetime,100);
		f.getline(evenote,100);
		eventlist[i].set_title(evetitle);
		eventlist[i].set_place(eveplace);
		eventlist[i].set_time(evetime);
		eventlist[i].set_note(evenote);
		delete[] evetitle;
		delete[] eveplace;
		delete[] evetime;
		delete[] evenote;
	}

	//Import Calendar
	f >> calendarcount;
	f.ignore(256,'\n');
	for (int i=0;i<calendarcount;i++){
		char* calname = new char[100];
		char* calauthor = new char[100];
		int calcount;
		f.getline(calname,100);
		f.getline(calauthor,100);
		f >> calcount;
		f.ignore(256, '\n');
		calendarlist[i].set_name(calname);
		calendarlist[i].set_author(calauthor);
		calendarlist[i].set_count(calcount);
		calendarlist[i].calendar = new Event[100];
		for (int j=0;j<calcount;j++){
			char * evetitle = new char [100];
			char * eveplace = new char [100];
			char * evetime = new char [100];
			char * evenote = new char [100];
			f.getline(evetitle,100);
			f.getline(eveplace,100);
			f.getline(evetime,100);
			f.getline(evenote,100);
			(calendarlist[i].calendar)[j].set_title(evetitle);
			(calendarlist[i].calendar)[j].set_place(eveplace);
			(calendarlist[i].calendar)[j].set_time(evetime);
			(calendarlist[i].calendar)[j].set_note(evenote);
			delete[] evetitle;
			delete[] eveplace;
			delete[] evetime;
			delete[] evenote;
		}
	}
}

void MainMenu(){
	//Main Menu
	int loop=0;
	while (loop==0){
		cout << endl << endl;
		cout << "Welcome to the main menu! What would you like to do?" << endl;
		cout << "1. Edit Trip details" << endl;
		cout << "2. Manage Cars and Participants" << endl;
		cout << "3. Manage Calendars and Events" << endl;
		cout << "4. Manage Playlists and Songs" << endl;
		if (saved==0){
			cout << "5. Save as .trip file" << endl;
		}
		else {
			cout << "5. Save " << endl;
		}
		//cout << "5. Load from saved .trip file" << endl;
		cout << "6. Export as .txt" << endl;
		cout << "0. Save and Exit" << endl;
		cout << "Your Choice: " ; 
		int c;
		cin >> c;
		while(cin.fail()) {
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> c;
		}
		while(c >6 || c <0){
		  cout << "Please enter a listed choice." << endl;
		  cin.clear();
		  cin.ignore(256,'\n');
		  cout << "Your choice: ";
		  cin >> c;
		}
		cin.ignore(100,'\n');
		switch (c){
		        case 1:
			  cout << "Edit Trip details" << endl;
			  edit_Trip();
			  break;
			case 2: 
				cout << "Set Car and Participant" << endl;
				SetCarParticipant();
				break;
			case 3: 
				cout << "Set Calendar and Event" << endl;
				SetCalEvent();
				break;
			case 4:
				cout << "Set Playlist and Song" << endl;
				SetPlaylistSong();
				break;
			case 5:
				if (saved==0){
					cout << "Save as .trip file" << endl;
					RoadTripSaveAs();
					saved=1;
				}
				else {
					cout << "Save" << endl;
					RoadTripSave();
				}
				break;
		        /*case 5:
				cout << "Load from saved .trip file" << endl;
				//RoadTripImport();
				break;*/
			case 6:
				cout << "Export as .txt" << endl;
				for(int i = 0; i < calendarcount;i++){
				  calendarlist[i].organize();
				}
				RoadTripExport();
				break;
			case 0: 
				loop = 1;
				cout << "Save and Exit" << endl;
				break;

		}

	}
}
	
	


int main(){
  char* tripname = new char[1000];
  char* authorname = new char [1000];
	//Start Setup
	cout << "Welcome to Road Trip Planner!" << endl;
	cout << "What would you like to do?"<< endl;
	cout << "1. Create new Trip"<< endl;
	cout << "2. Load from saved .trip file" << endl;
	cout << "Your choice: ";
	int choice;
	cin >> choice;
	while(cin.fail()) {
	  cout << "Please enter a listed choice" << endl;
	  cin.clear();
	  cin.ignore(256,'\n');
	  cout << "Your choice: ";
	  cin >> choice;
	}
	while(choice >2 || choice <1){
	  cout << "Please enter a listed choice" << endl;
	  cin.clear();
	  cin.ignore(256,'\n');
	  cout << "Your choice: ";
	  cin >> choice;
	}
	cin.ignore(100,'\n');
	if (choice == 2){
	  cout << "Load from saved .trip file" << endl;
	  RoadTripImport();
	}
	else{
	  float gascost;
	  cout << "Please name your Trip: " << endl;
	  cin.getline(tripname,1000);
	  t1.set_trip(tripname);
	  cout << "Please enter the Author of this Trip: " <<endl;
	  cin.getline(authorname,1000);
	  t1.set_author(authorname);
	  cout << "Please enter the Cost of Gas per gallon for this Trip: " << endl;
	  cin >> gascost;
	  while(cin.fail()) {
	    cout << "Please enter a float." << endl;
	    cin.clear();
	    cin.ignore(256,'\n');
	    cout << "Your choice: ";
	    cin >> gascost;
	  }
	  cin.ignore(100,'\n');
	  t1.set_gas(gascost);
	}
	delete [] tripname;
	delete [] authorname;
	MainMenu();
}
