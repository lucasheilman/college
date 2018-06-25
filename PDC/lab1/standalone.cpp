#include <iostream>
using namespace std;
#include <cmath>

class Trap {

protected:
  static double f(double x) {
    return (1/x);
  }

public:
  static double approxIntegral(double a, double b, int n, double h) {
    double integral;
   
    integral = (f(a) + f(b))/2.0;
    for(int i = 1; i < n; i++) {
      integral = integral + f(a + i*h);
    }
    integral = integral * h;

    return integral;
  }
};

/* Begin C++ Program */
int main(int argc, char** argv) {
  /* Variables */
  
  double a = 1.0;  // lower limit for integral
  double b = 2.0;  // upper limit for integral
  int n = 1048576;  // number of subdivisions
  
  /* Compute this node's part of the integral */
  double h = (b - a) / n;
  double integral = Trap::approxIntegral(a, b, n, h);
  cout << "With n = " << n << " trapezoids, our estimate" << endl;
  cout << "of the integral from " << a << " to " << b << " = " << 
      integral << endl;
  
}
