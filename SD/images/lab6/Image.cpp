#include <iostream>
#include <fstream>
using namespace std;
#include "Image.h"

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

void Image::zeroRed(){
  for(int y = 0; y<height; y++){
    for(int x = 0;x<width;x++){
      data[y][x].red = 0;
    }
  }
}

void Image::greyScale(){
  for (int y = 0;y<height;y++){
    for (int x = 0;x<width;x++){
      int b;
      b = ((data[y][x].red+data[y][x].green+data[y][x].blue)/3);
      data[y][x].red = b;
      data[y][x].green = b;
      data[y][x].blue = b;
    }
  }
}

void Image::horizSqueeze(){
  for (int y = 0;y<height;y++){
    for (int x = 0;x<width;x=x+2){
      data[y][(x)].red = data[y][(x)].red;
      data[y][(x)].green = data[y][(x)].green;
      data[y][(x)].blue = data[y][(x)].blue;
    }
  }
  width = width/2;
}

void Image::addBorder(){
  for( int y = 0; y < height; y++ ){
    for( int x = 0; x < width; x++ ){
      if (y<10){
	data[y][x].red = 255;
	data[y][x].green = 0;
	data[y][x].blue = 0;
      }
      else if (x<10){
	data[y][x].red = 255;
	data[y][x].green = 0;
	data[y][x].blue = 0;
      }
      else if (x>(width-10)){
	data[y][x].red = 255;
	data[y][x].green = 0;
	data[y][x].blue = 0;
      }
      else if (y>(height-10)){
	data[y][x].red = 255;
	data[y][x].green = 0;
	data[y][x].blue = 0;
      }
      else{}
    }
  }
}

Image::Image(int w, int h){
  width = w;
  height = h;
  data = new Pixel*[w*h];
}

Image::~Image(){
  for(int i = 0; i < height; i++){
    delete [] data[i];
  }
  delete data;}
