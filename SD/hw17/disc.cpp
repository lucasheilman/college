#include<iostream>
using namespace std;

class UltimateFrisbee {
  int size;
  float *data;
public:
  UltimateFrisbee() {
    size = 0; data = 0;
  }
  UltimateFrisbee(int s) {
    size = s; data = new float[size];
  }
  UltimateFrisbee(const UltimateFrisbee &uf){
    size = uf.size;
    data = new float[size];
    for(int i = 0;i<size;i++){
      data[i] = uf.data[i];
    }
  }
    
  ~UltimateFrisbee(){
    cout << "bye!" << endl; if ( data ) delete [] data;
  }
  void display(){
    cout << "size " << size << endl;
  }
};

int main()
{
  UltimateFrisbee g1, g2(3), g3(g2);

  g1.display();
  g2.display();
  g3.display();
}
