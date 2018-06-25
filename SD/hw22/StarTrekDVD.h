#ifndef _StarTrekDVD_H_
#define _StarTrekDVD_H_
#include "DVD.h"

class StarTrekDVD: public DVD {
 protected:
  char *makecopy(const char *);
 public:
  int episode;
  char *captain;
  StarTrekDVD(int, const char *, const char *, int, const char *);
  StarTrekDVD();
  StarTrekDVD(const StarTrekDVD &);
  ~StarTrekDVD();
  int getEpisode();
  char *getCaptain();
  void display();
  void setEpisode(int);
  void setCaptain(const char *);
  StarTrekDVD& operator=(const StarTrekDVD&);
};

#endif /* _StarTrekDVD_H_ */
