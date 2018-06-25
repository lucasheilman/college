#ifndef _DVDArray_H_
#define _DVDArray_H_
#include "DVD.h"

class DVDArray {
 protected:
  static int DEFAULT_SIZE;
 public:
  DVD *elt;
  int size;
  DVDArray(int);
  DVDArray();
  DVDArray(const DVDArray &);
  ~DVDArray();
  int getSize();
  void display();
  DVDArray& operator=(const DVDArray&);
  DVD &operator[](int);  
};

#endif /* _DVDArray_H_ */
