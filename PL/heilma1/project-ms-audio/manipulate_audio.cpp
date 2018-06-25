#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string length;
  cin >> length;
  int minutes = length[0] - '0';
  int tens_seconds = length[2] - '0';
  int ones_seconds = length[3] - '0';
  int seconds = minutes*60 + tens_seconds*10 + ones_seconds;
  signed short val;
  vector <vector <signed short> > effects;
  vector <signed short> values;
  while(cin >> val)
    {
      values.push_back(val);
    }
  int nums_per_second = values.size()/seconds;
  int start_faster = 1;
  int end_faster = 2;
  int start_slower = 2;
  int end_slower = 3;
  int start_louder = 3;
  int end_louder = 4;
  int start_softer = 4;
  int end_softer = 5;
  int start_octaveup = 5;
  int end_octaveup = 6;
  int start_octavedown = 6;
  int end_octavedown = 7;
  int num_effects = 7;
  string file = "xmas";

  vector <string> string_effects;
  string_effects.push_back("normal");
  string_effects.push_back("faster"); 
  string_effects.push_back("slower"); 
  string_effects.push_back("louder");
  string_effects.push_back("softer");
  string_effects.push_back("higher");
  string_effects.push_back("lower");

  vector <signed short> normal;
  normal.assign(values.begin(), values.begin()+start_faster*nums_per_second);
  effects.push_back(normal);

  vector <signed short> faster;
  faster.assign(values.begin()+start_faster*nums_per_second, values.begin()+end_faster*nums_per_second);
  effects.push_back(faster);

  vector <signed short> slower;
  slower.assign(values.begin()+start_slower*nums_per_second, values.begin()+end_slower*nums_per_second);
  effects.push_back(slower);

  vector <signed short> louder;
  louder.assign(values.begin()+start_louder*nums_per_second, values.begin()+end_louder*nums_per_second);
  effects.push_back(louder);

  vector <signed short> softer;
  softer.assign(values.begin()+start_softer*nums_per_second, values.begin()+end_softer*nums_per_second);
  effects.push_back(softer);

  vector <signed short> octaveup;
  octaveup.assign(values.begin()+start_octaveup*nums_per_second, values.begin()+end_octaveup*nums_per_second);
  effects.push_back(octaveup);

  vector <signed short> octavedown;
  octavedown.assign(values.begin()+start_octavedown*nums_per_second, values.begin()+end_octavedown*nums_per_second);
  effects.push_back(octavedown);

  for(int it = 0; it < seconds; it++)
    {
      ofstream myfile;
      string filename = "edited/" + file + "/" +  to_string(it) + ".txt";
      myfile.open (filename);
      if(string_effects[it] == "normal")
	{
	  for(int i = 0; i < effects[it].size(); i++)
	    {
	      myfile << effects[it][i] << " ";
	    }
	}
      if(string_effects[it] == "higher")
	{
	  ofstream higherfile;
	  string filename = "edited/" + file + "/pitch-" +  to_string(it) + ".txt";
	  higherfile.open (filename);
	  higherfile << "1000";
	  higherfile << endl;
	  higherfile.close();
	  for(int i = 0; i < effects[it].size(); i++)
	    {
	      myfile << effects[it][i] << " ";
	    }
	}
      if(string_effects[it] == "lower")
	{
	  ofstream lowerfile;
	  string filename = "edited/" + file + "/pitch-" +  to_string(it) + ".txt";
	  lowerfile.open (filename);
	  lowerfile << "-1000";
	  lowerfile << endl;
	  lowerfile.close();
	  for(int i = 0; i < effects[it].size(); i++)
	    {
	      myfile << effects[it][i] << " ";
	    }
	}
      if(string_effects[it] == "louder")
	{
	  ofstream louderfile;
	  string filename = "edited/" + file + "/vol-" +  to_string(it) + ".txt";
	  louderfile.open (filename);
	  louderfile << "5";
	  louderfile << endl;
	  louderfile.close();
	  for(int i = 0; i < effects[it].size(); i++)
	    {
	      myfile << effects[it][i] << " ";
	    }
	}
      if(string_effects[it] == "softer")
	{
	  ofstream softerfile;
	  string filename = "edited/" + file + "/vol-" +  to_string(it) + ".txt";
	  softerfile.open (filename);
	  softerfile << ".25";
	  softerfile << endl;
	  softerfile.close();
	  for(int i = 0; i < effects[it].size(); i++)
	    {
	      myfile << effects[it][i] << " ";
	    }
	}
      if(string_effects[it] == "faster")
	{
	  ofstream fasterfile;
	  string filename = "edited/" + file + "/speed-" +  to_string(it) + ".txt";
	  fasterfile.open (filename);
	  fasterfile << "2";
	  fasterfile << endl;
	  fasterfile.close();
	  for(int i = 0; i < effects[it].size(); i++)
	    {
	      myfile << effects[it][i] << " ";
	    }
	}
      if(string_effects[it] == "slower")
	{
	  ofstream slowerfile;
	  string filename = "edited/" + file + "/speed-" +  to_string(it) + ".txt";
	  slowerfile.open (filename);
	  slowerfile << ".5";
	  slowerfile << endl;
	  slowerfile.close();
	  for(int i = 0; i < effects[it].size(); i++)
	    {
	      myfile << effects[it][i] << " ";
	    }
	}

      myfile << endl;
      myfile.close();
    }

  return 0;
}

