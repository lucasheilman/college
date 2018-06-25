#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string oldval;
  cout << "enter the value to replace: ";
  getline(cin,oldval);
  string newval;
  cout << "enter the new value: ";
  getline(cin,newval);
  string listvals;
  cout << "enter your list as you would in scheme: ";
  getline(cin,listvals);
  for(int i = 0; i < listvals.length()-newval.length()+1; i++)
    {
      if(listvals.substr(i,oldval.length()) == oldval)
	{
	  if(listvals[i+newval.length()] == ' ')
	    {
	      listvals.replace(i,oldval.length(),newval);
	    }
	  else if(listvals[i+newval.length()] == ')')
	    {
	      listvals.replace(i,oldval.length(),newval);
	    }
	}
    }
  cout << listvals << endl;
}
      
