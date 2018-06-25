#ifndef _IntArray_H_
#define _IntArray_H_

class IntArray {
 protected:
  static int DEFAULT_SIZE;
 public:
  int *elt;
  int size;
  IntArray(int);
  IntArray();
  IntArray(const IntArray &);
  ~IntArray();
  int getSize();
  void display();
  IntArray& operator=(const IntArray&);
  int &operator[](int);  
};

#endif /* _IntArray_H_ */
