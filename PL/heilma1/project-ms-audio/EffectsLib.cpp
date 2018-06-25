#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Volume effects
void louder(int amount, int sec) {
	ofstream louderfile;
	string filename = "edited/" + file + "/vol-" +  to_string(sec) + ".txt";
	louderfile.open (filename);
	louderfile << amount;
	louderfile << endl;
	louderfile.close();
}

void softer(int amount, int sec) {
	ofstream softerfile;
	string filename = "edited/" + file + "/vol-" +  to_string(sec) + ".txt";
	softerfile.open (filename);
	softerfile << amount;
	softerfile << endl;
	softerfile.close();
}

// Speed effects
void faster(int amount, int sec) {
	ofstream fasterfile;
	string filename = "edited/" + file + "/speed-" +  to_string(sec) + ".txt";
	fasterfile.open (filename);
	fasterfile << amount;
	fasterfile << endl;
	fasterfile.close();
}

void slower(int amount, int sec) {
	ofstream slowerfile;
	string filename = "edited/" + file + "/speed-" +  to_string(sec) + ".txt";
	slowerfile.open (filename);
	slowerfile << amount;
	slowerfile << endl;
	slowerfile.close();
}

// Pitch effects
void higher(int amount, int sec) {
	ofstream higherfile;
	string filename = "edited/" + file + "/pitch-" +  to_string(sec) + ".txt";
	higherfile.open (filename);
	higherfile << amount;
	higherfile << endl;
	higherfile.close();
}

void lower(int amount, int sec) {
	ofstream lowerfile;
	string filename = "edited/" + file + "/pitch-" +  to_string(sec) + ".txt";
	lowerfile.open (filename);
	lowerfile << amount;
	lowerfile << endl;
	lowerfile.close();
}