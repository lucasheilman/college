#ifndef _MVECTOR_H_
#define _MVECTOR_H_

class Mvector{
  static int default_len;
 public:
  int len;
  float *arr;
  Mvector(int length);
  Mvector();
  int get_len();
  void dump();
  ~Mvector();
  Mvector& operator= (const Mvector& mvec);
  float& operator[] (int index);
  Mvector operator* (float val);
  Mvector operator* (const Mvector &vec);
  Mvector operator+ (const Mvector &vec);
};
#endif
