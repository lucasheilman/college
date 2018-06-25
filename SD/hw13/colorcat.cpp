#include<iostream>
using namespace std;

/** A feline */
struct Cat {
  int color;
  double weight;  /**< Weight in pounds */
  void grow() { /** Increase the weight of Cat c */
    weight *= 1.1;
  }
  void setcolor(int x){ /** change the color of Cat c */ 
    color = x;
  }
};

int main()
{
  Cat misty, dusty;
  dusty.color = 3;
  dusty.weight = 2;
  cout << "dusty is colored " << dusty.color << endl;   // dusty is colored 3
  dusty.setcolor(4);
  cout << "dusty is now colored " << dusty.color << endl;   // dusty is colored 4
}
