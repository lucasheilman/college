#ifndef _CAR_H_
#define _CAR_H_
#include "Participant.h"
#include "trip.h"

/** Represents a Car */
class Car{
  int count;
  static int DEFAULT_SIZE;
  char *name; /**< name for this car */
  float mpg; /**< mpg for this car */
 public:
  Participant *passengers; /**< array of passengers for this car */
  /** Default constructor */
  Car();
  /** 1-argument constructor
      @param n Name for this Car */
  Car(const char *n);
  /** 2-argument constructor
      @param n Name for this Car 
      @param m mpg for this Car */
  Car(const char *n, float m);
  /** set the name for this Car
      @param n Name for this Car */
  void set_name(const char *n);
  /** get the name for this Car
      @return the name of this Car */
  char *get_name();
  /** set the mpg for this Car 
      @param m mpg for this Car */
  void set_mpg(float m);
  /** get the mpg for this Car
      @return the mpg for this Car */
  float get_mpg();
  /** get the count of the passengers 
      @return the count of passengers */
  int get_count();
  /** sets the count of the passengers
      @param c count of the passengers */
  void set_count(int c);
  /** adds a participant to the passengers array
      @param p a Participant */
  void add_participant(const Participant &p);
  /** shows the list of Participants in passengers array */
  void display_participant();
  /** displays the details of the car */
  void display();
  ~Car();
  char *makeString(const char*str);
};
#endif
