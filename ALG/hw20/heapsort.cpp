#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class heap {
public:
  vector <int> pile; 
  void insert(int num) {
    int i = pile.size();
    pile.push_back(num);
    while(i > 0 && pile[floor(i/2)] > num && pile.size() > 1){
      int temp = pile[i];
      pile[i] = pile[floor(i/2)];
      pile[floor(i/2)] = temp;
      i = floor(i/2);
    }
  }
  int deleteMin (){
    if(pile.size() == 0){
      cout << "Pile is empty" << endl;
      return false;
    }
    int deleted = pile[0];
    //cout << "First/deleted = " << deleted << endl;
    pile[0] = pile.back();
    //cout << "New top = " << pile[0] << endl;
    pile.pop_back();
    int next = 0;
    int i = 0;
    int power = 0;
    while((pile[i] > pile[next] || pile[i] > pile[next+1]) && next < pile.size()){
      if(pile[i] > pile[next]){
	int temp = pile[next];
	pile[next] = pile[i];
	pile[i] = temp;
	i = next;
      }
      else if(pile[i] > pile[next+1]){
	int temp = pile[next+1];
	pile[next+1] = pile[i];
	pile[i] = temp;
	i = next + 1;
      }
      next = pow(2,power);
      power++;
    }
    return deleted;
  }

  bool display(){
    if(pile.size() == 0){
      cout << "Pile is empty" << endl;
      return false;
    }
    cout << '[';
    for(int i = 0; i < pile.size()-1; i++){
      cout << pile[i] << ", ";
    }
    cout << pile[pile.size()-1] << ']' << endl;
    return true;
  }
};
void fullsort(vector <int> arr){
  heap myheap;
  for(int x = 0; x < arr.size(); x++){
    myheap.insert(arr[x]);
  }
  vector <int> sorted;
  int size = myheap.pile.size();
  for(int i = 0; i < size; i++){
    sorted.push_back(myheap.deleteMin());
  }
  cout << '[';
  for(int i = 0; i < sorted.size()-1; i++){
    cout << sorted[i] << ", ";
  }
  cout << sorted[sorted.size()-1] << ']' << endl;
}
int main() {
  vector <int> vec = {7,15,14,8,2,3};
  fullsort(vec);
  return 0;
}
