#include <iostream>
#include <vector>
using namespace std;

bool is_leaf(vector <int> vec, int i)
{
  return (i*2 >= vec.size());
}

int lson(vector <int> vec, int i)
{
  if(is_leaf(vec,i))
    {
      return -1;
    }
  return (vec[i*2+1]);
}

int rson(vector <int> vec, int i)
{
  if(is_leaf(vec,i))
    {
      return -1;
    }
  return (vec[i*2+2]);
}

int contents_of(vector <int> vec, int i)
{
  return vec[i];
}

int main()
{
  vector <int> vec = {2,3,5,8,4,2,4,7,0,1,5};
  cout << is_leaf(vec, 0) << endl;
  cout << is_leaf(vec, 10) << endl;
  cout << rson(vec, 0) << endl;
  cout << lson(vec, 0) << endl;
  cout << contents_of(vec, 0) << endl;
}
