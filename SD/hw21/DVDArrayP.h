#ifndef _DVDArrayP_H_
#define _DVDArrayP_H_
#include "DVD.h"

class DVDArrayP {
 protected:
  static int DEFAULT_SIZE;
 public:
  DVD **elt;
  int size;
  DVDArrayP(int);
  DVDArrayP();
  DVDArrayP(const DVDArrayP &);
  ~DVDArrayP();
  int getSize();
  void display();
  DVDArrayP& operator=(const DVDArrayP&);
  DVD &operator[](int);  
};

#endif /* _DVDArrayP_H_ */
