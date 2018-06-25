#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class heap {
private:
    vector <int> pile;
public:

    void insert (int num) {
        int i = pile.size();
        pile.push_back(num);
        while(i > 0 && pile[floor(i/2)] > num && pile.size() > 1){
            int temp = pile[i];
            pile[i] = pile[floor(i/2)];
            pile[floor(i/2)] = temp;
            i = floor(i/2);
        }

    }
    bool deleteMin (){
      if(pile.size() == 0){
	cout << "Pile is empty" << endl;
	return false;
      }
        int deleted = pile[0];
        cout << "First/deleted = " << deleted << endl;
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
	return true;
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

int main() {
    heap a;
    
    a.insert(8);
    a.insert(7);
    a.insert(15);
    a.insert(14);
    a.insert(2);
    a.insert(16);
    a.insert(18);
    a.display();
    a.deleteMin();
    a.display();
    a.deleteMin();
    a.display();
    a.deleteMin();
    a.display();
    a.deleteMin();
    a.display();
    a.deleteMin();
    a.display();
    a.deleteMin();
    a.display();
    a.deleteMin();
    a.display();
    a.deleteMin();
    
    return 0;
}
