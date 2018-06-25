#include<iostream>
using namespace std;

struct Pixel{
  int red;
  int green;
  int blue;
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
  

  cout << "P6" << endl; 
  cout << width << " " << height << endl;
  cout << range << endl;
   for(int i = 0; i<(height);i++){
     cout.write((char *)image[i], width*sizeof(Pixel));
    }
  image[0][0].red = 255;
  cout << image[0][0].red;
  cout << endl;
  return 0;
}
