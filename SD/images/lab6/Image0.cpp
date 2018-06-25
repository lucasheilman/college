#include <iostream>
using namespace std;

class Image0{
  int width;
  int height;
public:
  Image0(int,int);
  int getWidth(){
    return width;
  }
  int getHeight(){
    return height;
  }
};

Image0::Image0(int w, int h){
  width = w;
  height = h;
  }

int main(){
  Image0 arg1(5,10);
  Image0 arg2(6,11);
  cout << arg1.getWidth() << " " << arg1.getHeight() << endl;
  cout << arg2.getWidth() << " " << arg2.getHeight() << endl;
}
