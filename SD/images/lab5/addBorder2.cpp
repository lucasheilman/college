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
  cout << width << " " << height << endl;
  cout << range << endl;
  for( int y = 0; y < height; y++ ){
    for( int x = 0; x < width; x++ ){
      if (y<10){
	image[y][x].red = 255;
	image[y][x].green = 0;
	image[y][x].blue = 0;
	cout << image[y][x].red;
	cout << image[y][x].green;
	cout << image[y][x].blue;
      }
      else if (x<10){
	image[y][x].red = 255;
	image[y][x].green = 0;
	image[y][x].blue = 0;
	cout << image[y][x].red;
	cout << image[y][x].green;
	cout << image[y][x].blue;
      }
      else if (x>(width-10)){
	image[y][x].red = 255;
	image[y][x].green = 0;
	image[y][x].blue = 0;
	cout << image[y][x].red;
	cout << image[y][x].green;
	cout << image[y][x].blue;
      }
      else if (y>(height-10)){
	image[y][x].red = 255;
	image[y][x].green = 0;
	image[y][x].blue = 0;
	cout << image[y][x].red;
	cout << image[y][x].green;
	cout << image[y][x].blue;
      }
      else{
	cout << image[y][x].red;
	cout << image[y][x].green;
	cout << image[y][x].blue;
      }
    }
  }
  cout << endl;
  return 0;
}
