#include<iostream>
using namespace std;

class Rugby {
  int size;
  float *data;
public:
  Rugby() { size = 0; data = 0; }
  Rugby(int s) { size = s; data = new float[size]; }
  Rugby( const Rugby &r );
  ~Rugby() { cout << "bye!" << endl; if (data) delete [] data; }

  void display()
    { cout << "size " << size << endl;}
};

Rugby::Rugby( const Rugby &r ) {
  size = r.size;
  data = new float[size];
  for ( int i = 0; i < size; ++i ) data[i] = r.data[i];
}

int main()
{
  Rugby r2(3), r3(r2);
  r2.display();
  r3.display();
}
