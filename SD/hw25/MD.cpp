#include<iostream>
using namespace std;
      
/** A base class (superclass) */                                                                          
class Animal { 
   protected:       // available to derived classes only
     int numlegs;
     bool aquatic;
   public:             // members that are available to any code
     Animal(int nlegs) : numlegs(nlegs), aquatic(false) {}
     void walk() { cout << "walking on " << numlegs 
                        << " legs" << endl; }
     void draw() { cout << "Animal draw" << endl; }
     virtual void eat() = 0; /**< pure virtual method  */
};
                                                                                
enum Mood {HAPPY=7, SAD=12, IRASCIBLE=65535};
     
/** A derived class (subclass) */                                                                           
class Clown : public Animal { 
  protected:
    Mood mood;
  public:
    Clown(int nlegs, Mood start) : Animal(nlegs), mood(start) {}
    void display() { cout << " :) " << aquatic << endl; }
    void draw() {  cout << "clown draw" << endl; } 
        // overrides the superclass method Animal::draw()
    virtual void eat() { cout << "Clown eat pie" << endl; }
        // implements the method Animal::eat()
};
                                                                                
int main()
{
  Clown Bozo(2, HAPPY);
  Bozo.display();
  Bozo.draw();
  Bozo.walk();
  Bozo.eat();
  Animal &monkey = Bozo;
  monkey.draw();
  monkey.eat();
}
