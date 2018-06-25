#ifndef _POLY_H_
#define _POLY_H_
#include "Mvector.h"

class Poly : public Mvector{
 public:
  float operator() (float x);
};
#endif
