#ifndef _DVD_H_
#define _DVD_H_

class DVD {
  int id;
  char *title;
  char *director;
 protected:
  char *makecopy(const char *);
 public:
  DVD(int, const char *,const char *);
  DVD();
  DVD(const DVD &);
  ~DVD();
  int getId();
  char *getTitle();
  char *getDirector();
  void display();
  void setId(int);
  void setTitle(const char *);
  void setDirector(const char *);
  DVD& operator=(const DVD&);
  int operator++();
  int operator++(int);
};

#endif /* _DVD_H_ */
