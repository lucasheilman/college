#ifndef _Menu_H_
#define _Menu_H_
#include <iostream>
using namespace std;
#include "Menu.h"
#include "MenuItem.h"

class Menu {
 protected:
  static int DEFAULT_SIZE;
 public:
  MenuItem **vec;
  int size;
  int count;
  int not_found;
  Menu(int);
  Menu();
  Menu(const Menu &);
  ~Menu();
  int get_size() const;
  int get_count();
  int get_not_found();
  int add_item(int,const char *);
  int add_item(const MenuItem&);
  void display(ostream &) const;
  Menu& operator=(const Menu&);
  MenuItem &operator[](int);
  int get_value(ostream &,istream &) const;
  void copyVec(const Menu&);
  void deleteVec();
};

#endif /* _Menu_H_ */
