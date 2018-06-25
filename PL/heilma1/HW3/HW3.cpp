#include<iostream>
#include <vector>
#include <string>
using namespace std;

struct node {
  string info;
  node *link;
  node(string i, node * l)
  {
    info = i;
    link = l;
  }
};

void remEvOth(node * current)
{
  node *next = current;
  while(current->link != NULL && next->link !=NULL)
    {
      cout << "next info: " << next->info << endl;
      if(current->link->link != NULL)
	{
	  next = current->link;
	  current->link = current->link->link;
	}
      else
	{
	  return;
	}
      current = next;
    }
}	

void addxxx(node *current)
{
  node *next = current;
  while(current->link != NULL && next->link != NULL)
    {
      cout << "next info: " << next->info << endl;
      next = current->link;
      if((next->info)[0] == 'g')
	{
	  next = current->link;
	  current->link = new node("xxx",next);
	}
      current = next;
    }
}

int main()
{
  vector <string> vec;
  string var;
  cout << "enter value, newline to exit: ";
  while(getline(cin,var))
  {
    if(var == "\0")
    {
        break;
    }
    vec.push_back(var);
    cout << "enter value, newline to exit: ";
  }
  node *next = new node(vec.back(), NULL);
  vec.pop_back();
  while(vec.size() > 0)
  {
    next = new node(vec.back(),next);
    vec.pop_back();
  }
  node *first = next;
  cout << first->info << endl;
  next = first->link;
  while(next != NULL)
  {
    cout << next->info << endl;
    next = next->link;
  }
  //remEvOth(first);
  addxxx(first);
  next = first;
  while(next != NULL)
  {
    cout << next->info << endl;
    next = next->link;
  }
}
