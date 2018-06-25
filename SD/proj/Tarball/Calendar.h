#ifndef _CALENDAR_H_
#define _CALENDAR_H_
#include "Event.h"
#include "trip.h"

/** Represents a Calendar */
class Calendar{
  int count;
  static int DEFAULT_SIZE;
  char *name; /**< name for this Calendar */
  char *author; /**< author for this Calendar */
 public:
  Event *calendar; /**< array of events for this Calendar */
  /** 2-argument constructor
      @param n Name for this Calendar 
      @param a author for this Calendar */
  Calendar(const char *n, const char* a);
  /** Default constructor */
  Calendar();
  /** set the name for this Calendar
      @param n Name for this Calendar */
  void set_name(const char *n);
  /** get the name for this Calendar
      @return the name of this Calendar */
  char *get_name();
  /** set the author for this Calendar 
      @param a author for this Calendar */
  void set_author(const char *a);
  /** get the author for this Calendar
      @return the author for this Calendar */
  char *get_author();
  /** get the count of events for this Calendar 
      @return the count of events for this Calendar */
  int get_count();
  /** set the count of events for this Calendar
      @param c count of events for this Calendar*/
  void set_count(int);
  /** adds an event to the calendar array
      @param e an event */
  void add_Event(const Event &e);
  /** displays the calendar information*/
  void display();
  /** shows the list of Eventss in event array */
  void display_event();
  ~Calendar();
  char *makeString(const char*str);
  /** organize the events in this calendar*/
  void organize();
};
#endif
