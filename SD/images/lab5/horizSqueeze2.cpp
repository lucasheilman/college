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
  cout << (width/2) << " " << height << endl;
  cout << range << endl;
  for( int y = 0; y < height; y++ ){
    for( int x = 0; x < width; x=x+2 ){
      cout << image[y][x].red;
      cout << image[y][x].green;
      cout << image[y][x].blue;
    }
  }
  cout << endl;
  return 0;
}
