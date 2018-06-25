#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  vector<string> a {"apple","banana","corn","date","eggplant","fig"};
    string val;
    cout << "Enter a word to see if it's in the array: ";
    cin >> val;
    cout << "Array: " << endl;
    cout << "[";
    for(int x = 0; x < 6-1; x++){
	cout << a[x] << ",";
    }
    cout << a[6-1] << "]" << endl;
    int index = -1;
    for(int y = 0; y <6; y++){
      if(a[y] == val){
	index = y;
      }
    }
    if(index == -1){
      cout << "Value is not in array" << endl;
    }
    else{
      cout << "Index of " << val << " is " << index << endl;
    }
}
