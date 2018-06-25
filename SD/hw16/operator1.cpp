#include <iostream>
using namespace std;

class CVector {
public:
  int x,y;
  CVector () {};
  CVector (int a,int b) : x(a), y(b) {}
  CVector operator + (const CVector&);
  CVector operator - (const CVector&);
  CVector operator * (const CVector&);
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

CVector CVector::operator- (const CVector& param) {
  CVector temp;
  temp.x = x - param.x;
  temp.y = y - param.y;
  return temp;
}

CVector CVector::operator* (const CVector& param) {
  CVector temp;
  temp.x = x*param.x;
  temp.y = y*param.y;
  return temp;
}

int main () {
  CVector foo (3,1);
  CVector bar (1,2);
  CVector result;
  result = foo + bar;
  CVector result1;
  result1 = foo - bar;
  CVector result2;
  result2 = foo*bar;
  cout << result.x << ',' << result.y << '\n';
  cout << result1.x << ',' << result1.y << '\n';
  cout << result2.x << ',' << result2.y << '\n';
  return 0;
}
