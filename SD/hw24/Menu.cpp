#include <iostream>
using namespace std;
#include "Menu.h"
#include "MenuItem.h"

int Menu::DEFAULT_SIZE = 20;

Menu::Menu(int sz){
  size = sz;
  vec = new MenuItem*[size];
  for(int i = 0; i<size;i++){
    vec[i]=0;
  }
  count = 0;
  not_found = -1;
}

Menu::Menu(){
  size = DEFAULT_SIZE;
  vec = new MenuItem*[size];
  count = 0;
  not_found = -1;
}

Menu::Menu(const Menu &m){
  size = m.size;
  count = m.count;
  not_found = m.not_found;
  vec = new MenuItem*[size];
  for(int i = 0; i < size; i++){
    if (m.vec[i] == 0){
      vec[i] = 0;
    }
    else{
      vec[i] = new MenuItem;
      *vec[i] = *m.vec[i];
    }
  }
}

Menu::~Menu(){
  for(int i =0;i<size;i++){
    delete vec[i];
  }
  delete[] vec;
}

int Menu::get_size() const{
  return size;
}

int Menu::get_count(){
  return count;
}

int Menu::get_not_found(){
  return not_found;
}

int Menu::add_item(int v1, const char *lbl){
  if (count < size){
    vec[count] = new MenuItem(v1,lbl);
    count ++;
    if(v1 < not_found){
      not_found = v1-1;
    }
    return 1;
  }
  else {
    return 0;
  }
}

int Menu::add_item(const MenuItem &item){
  if(count < size){
    vec[count] = new MenuItem(item);
    count ++;
    if (item.val < not_found){
      not_found = item.val - 1;
    }
    return 1;
  }
  else{
    return 0;
  }
}
  
void Menu::display(ostream &ostr) const{
  ostr << "size=" << size << " count=" << count << " not_found=" << not_found << endl;
  for(int i = 0;i<size;i++){
    if ((vec[i])!=0){
      ostr << i << ". " << '[' << vec[i]->get_val() << "] " << vec[i]->get_label() << endl;
    }
  }
}

Menu& Menu::operator= (const Menu &m){
  size = m.size;
  count = m.count;
  not_found = m.not_found;
  vec = new MenuItem*[size];
  for(int i = 0; i < size; i++){
    if (m.vec[i] == 0){
      vec[i] = 0;
    }
    else{
      vec[i] = new MenuItem;
      *vec[i] = *m.vec[i];
    }
  }
  return *this;
}

MenuItem& Menu::operator[](int index){
  if(index<0){
    cout << "The value inputed was too low" << endl;
    return *vec[0];
  }
  else if(index>(size-1)){
    cout << "The value inputed was too high" << endl;
    return *vec[size-1];
  }
  else{
    return *vec[index];
  }
}

int Menu::get_value(ostream &ostr, istream &istr) const{
  for(int i = 1;i<size+1;i++){
    if ((vec[i-1])!=0){
      ostr << "  " << i << ". " << vec[i-1]->get_label() << endl;
    }
  }
  ostr << "Your choice (1-" << count << "): ";
  int choice;
  istr >> choice;
  if(choice < size){
    if(choice > 0){
      return (vec[choice-1]->get_val());
    }
    else{
      return not_found;
    }
  }
  else{
    return not_found;
  }
}

void Menu::copyVec(const Menu &m){
  vec = new MenuItem*[m.get_size()];
  for(int i = 0; i<m.get_size(); i++){
    vec[i] = m.vec[i];
  }
}

void Menu::deleteVec(){
  for(int i =0;i<size;i++){
    delete vec[i];
  }
  delete[] vec;
}
