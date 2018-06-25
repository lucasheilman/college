#ifndef _EVENT_H_
#define _EVENT_H_

/** Represents an Event */
class Event {
  long timestamp; /** timestamp for this Event*/
  char* time; /** time of this Event */
  char* place; /** place for this Event*/
  char* note; /** note for this Event*/
  char* title; /** title for this Event*/

  /** dynamically copies the string  
      @param str string to be copied*/
  char* copystring(const char* str); 
 public:

  /** 4-argument constructor
      @param t title of this Event
      @param ti time of this Event
      @param pla place of this Event
      @param n note for this Event*/
  Event(const char *t, const char* ti, const char *pla, const char* n);

  Event();

  Event(const Event&);

  /** Destructor */
  ~Event();

  /** set title for this event
      @param t title to be set*/
  void set_title(const char* t);

  /** set time for this event
      @param ti time to be set*/
  void set_time(const char* ti);

  /** set place for this event
      @param pla place to be set*/
  void set_place(const char* pla);

  /** set note for this event
      @param n note to be set*/
  void set_note(const char* n);

  /** get title of this event*/
  char* get_title();

  /** get place of this event */
  char* get_place();

  /** get time of this event */
  char * get_time();

  /** get note of this event*/
  char* get_note();

  /** get timestamp of this event*/
  long get_timestamp();

  /** print details of the Event */
  void display();

  /** finds timestamp for event*/
  void findtimestamp(const char*);

  Event& operator= (const Event&);
};

#endif
