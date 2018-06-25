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
  for(int i = 0; i < height; ++i){
      image[i] = new Pixel[width];
      cin.read((char *)image[i],width*sizeof(Pixel));
    }
  for( int y = 0; y < height; y++ ){
    for( int x = 0; x < width; x++ ){
      int b;
      b = ((image[y][x].red + image[y][x].green + image[y][x].blue)/3);
      image[y][x].red = b;
      image[y][x].green = b;
      image[y][x].blue = b;
    }
  }
  cout << "P6" << endl; 
  cout << width << " " << height << endl;
  cout << range << endl;
   for(int a = 0; a<height;a++){
     cout.write((char *)image[a], width*sizeof(Pixel));
    }
  cout << endl;
  return 0;
}
