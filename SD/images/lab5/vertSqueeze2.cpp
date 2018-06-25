#include<iostream>
using namespace std;

struct Pixel{
  char red;
  char green;
  char blue;
}; 

int main()
{
  string s;
  cin >> s; 
  int width, height, range; 
  cin >> width >> height >> range;
  cin.get();
  Pixel **image;
  image  = new Pixel*[height];
  for(int i = 0; i < height; i++){
      image[i] = new Pixel[width];
      cin.read((char *)image[i],width*sizeof(Pixel));
    }
  cout << "P6" << endl; 
  cout << width << " " << (height/2) << endl;
  cout << range << endl;
  for(int i = 0; i<height;i=i+2){
     cout.write((char *)image[i], width*sizeof(Pixel));
  }
  cout << endl;
  return 0;
}
