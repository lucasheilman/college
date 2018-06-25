#include <iostream>
#include <fstream>
using namespace std;

struct Pixel{
  char red;
  char green;
  char blue;
}; 

class Image{
  int width;
  int height;
  int depth;
  Pixel **data;
public:
  Image(int,int);
  Image(const char*);
  ~Image(){
    for(int i = 0; i < height; i++){
      delete [] data[i];
    }
    delete data;}
  int getWidth(){
    return width;
  }
  int getHeight(){
    return height;
  }
  void print();
};

Image::Image(const char* str){
  ifstream g(str);
  string s;
  g >> s; 
  g >> width >> height >> depth;
  g.get();
  data  = new Pixel*[height];
  for(int i = 0; i < height; i++){
    data[i] = new Pixel[width];
    g.read((char *)data[i],width*sizeof(Pixel));
  }
  g.close();
}

void Image::print(){
  cout << "P6" << endl; 
  cout << width << " " << height << endl;
  cout << depth << endl;
  for(int i = 0; i<height; i++){
    cout.write((char *)data[i], width*sizeof(Pixel));
  }
}
Image::Image(int w, int h){
  width = w;
  height = h;
  data = new Pixel*[w*h];
}

int main(){
  Image arg1("newfile.ppm");
  arg1.print();
}
