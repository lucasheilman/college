#include <iostream>
using namespace std;
#ifndef _MenuItem_H_
#define _MenuItem_H_

class MenuItem {
 protected:
  char *makeString(const char *);
 public:
  int val;
  char *label;
  MenuItem(int, const char *);
  MenuItem();
  MenuItem(const MenuItem&);
  ~MenuItem();
  int get_val();
  char *get_label();
  void display(ostream &) const;
  void set_val(int);
  void set_label(const char *);
  MenuItem& operator=(const MenuItem&);
};

#endif /* _MenuItem_H_ */
