#include <iostream>
using namespace std;

class Rating{
public:
  int id, stars;
  Rating(int,int);
  int set_stars(int a){
    stars = a;
  }
  int get_id(){
    return id;
  }
  int get_stars(){
    return stars;
  }
  int display(ostream &a){
    if (stars == 1){
      a << id << ":* ";
    }
    else if (stars == 2){
      a << id << ":** ";
    }
    else if (stars == 3){
      a << id << ":*** ";
    }
    else if (stars == 4){
      a << id << ":**** ";
    }
    else{
      a << id << ":***** ";
    }
  }
};
  

Rating::Rating(int a,int b){
  id = a;
  if(b>5){
    stars = 5;
  }
  else if (b<1){
    stars = 1;
  }
  else{
    stars = b;
  } 
}

int main() {
  Rating r(1234, 3);
  cout << "Rating r contains ";   r.display(cout);  cout << endl;
  r.set_stars(4);
  cout << "After r.set_stars(4), id=" << r.get_id() 
       << " and stars=" << r.get_stars() << endl;

  Rating *arr[8];
  int i;
  for (i = 0;  i < 8;  i++)
    arr[i] = new Rating(100+i, i);
  cout << "Ratings in array arr:  ";
  for (i = 0;  i < 8;  i++)
    arr[i]->display(cout); cout << "  ";
  cout << endl;    
}
