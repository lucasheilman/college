#ifndef _DVD_H_
#define _DVD_H_

class DVD {
 protected:
  char *makecopy(const char *);
 public:
  int id;
  char *title;
  char *director;
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
};

#endif /* _DVD_H_ */
