#include <iostream>
#include <vector>
using namespace std;

struct node
{
  int a,b,c;
};

/* We use add and sub for handling the pouring into different sized
   containers */
int add (int a, int b, int base) {
  if (a+b >= base) return base;
  else return a+b;
}

int sub (int a, int b, int base) {
  int diff = add(a,b,base)-b;
  // if (a-diff <= 0) return 0;  // could be a problem
  return a-diff;
}

/* Returns the possible paths from a certain combination of containers */
vector <node> pour (node & n) {
  vector <node> combos;
  node n1 = {sub(n.a,n.b,7), add(n.a,n.b,7), n.c};
  node n2 = {sub(n.a,n.c,4), n.b, add(n.a,n.c,4)};
  node n3 = {add(n.b,n.a,10), sub(n.b,n.a,10), n.c};
  node n4 = {n.a, sub(n.b,n.c,4), add(n.b,n.c,4)};
  node n5 = {add(n.c,n.a,10), n.b, sub(n.c,n.a,10)};
  node n6 = {n.a, add(n.c,n.b,7), sub(n.c,n.b,7)};
  combos.push_back(n6);
  combos.push_back(n2);
  combos.push_back(n3);
  combos.push_back(n4);
  combos.push_back(n5);
  combos.push_back(n1);
  return combos;
}

/* Recursive function that performs DFS to find first possible path
   from current node n that satisfies the criteria */
void search (node start) {
  vector <node> queue;
  queue.push_back(start);
  bool notYetFound = true;
  int level = 0;
  bool notfinish = true;
  while(notYetFound || notfinish)
    {
      for(int x = 0; x < queue.size(); x++)
	{
	  if (queue[x].b == 2 || queue[x].c == 2) {
	    cout << queue[x].a << " " << queue[x].b << " " << queue[x].c << endl;
	    cout << "Shortest distance = " << level << endl;
	    notYetFound = false;
	    //return true;
	  }
	}
      int queueSize = queue.size();
      for(int count = 0; count < queueSize; count++)
	{
	  vector <node> combos;
	  combos = pour(queue.front());
	  queue.erase(queue.begin());
	  queue.insert(queue.end(), combos.begin(), combos.end());
	}
      level++;
      if(level == 11){
	notfinish = false;
      }
    }
}

int main () {
  node first = {0,7,4};
  vector <node> visited;
  node n1 = {-1,-1,-1};
  visited.push_back(n1);
  search(first);
}
