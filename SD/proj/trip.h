#ifndef _trip_H_
#define _trip_H_
#include "Participant.h"
#include "Car.h"

/** Represents a Car */
class Trip{
  char *title; /**< name for this trip */
  char *author; /**< name for this author */
  float gas; /** cost of gas for this trip*/
 public:
  /** default constructor */
  Trip();
  /** 1-argument constructor
      @param t title for this trip */
  Trip(const char *t);
  /** 2-argument constructor
      @param t title for this trip 
      @param a author for this trip 
      @param g gas cost for this trip*/
  Trip(const char *t, const char *a, float g);
  /** set the name for this trip
      @param t title for this trip */
  ~Trip();
  void set_trip(const char *t);
  /** get the name for this trip
      @return the name of this trip */
  char *get_trip();
  /** set the author for this trip 
      @param a author for this trip */
  void set_author(const char *a);
  /** get the author for this trip
      @return the author for this trip */
  char* get_author();
  /** get the cost of gas for this trip
      @return the cost of gas for this trip*/
  float get_gas();
  /** set the cost of gas for this trip
      @param g the cost of gas for this trip*/
  void set_gas(float);
  /** Print out trip onto standard output */
  void print();
};
#endif
