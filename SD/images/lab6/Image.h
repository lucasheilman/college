#ifndef _IMAGE_
#define _IMAGE_

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
  ~Image();
  int getWidth(){
    return width;
  }
  int getHeight(){
    return height;
  }
  void print();
  void zeroRed();
  void greyScale();
  void horizSqueeze();
  void addBorder();
};

#endif // _IMAGE_

