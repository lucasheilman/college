#ifndef _PARTICIPANT_H_
#define _PARTICIPANT_H_

/** Represents a Participant */
class Participant {
  char* name; /** name of this participant */
  char* destination; /** destination for this participant*/
  float distance; /** distance that participant will have traveled*/

  /** dynamically copies the string  
      @param str string to be copied*/
  char* copystring(const char* str); 
 public:
  /** 1-argument constructor
      @param n Name for this Participant*/
  Participant(const char *n);
  
  /** 2-argument constructor
      @param n Name of this Participant 
      @param dest Destination of this Participant */
  Participant(const char *n, const char* dest);

  /** 3-argument constructor
      @param n Name of this Participant
      @param dest Destination of this Participant
      @param dist Distance this Participant will have traveled */
  Participant(const char *n, const char* dest, float dist);

  /** Default Constructor */
  Participant();

  /** Destructor */
  ~Participant();

  /** set name for this Participant 
      @param n Name to be set*/
  void set_name(const char* n);

  /** set destination for this Participant 
      @param dest destination to be set*/
  void set_destination(const char* dest);

  /** set distance for this Participant 
      @param dist distance to be set*/
  void set_distance(float dist);

  /** get name of this Participant*/
  char* get_name();	

  /** get destination of this Participant */
  char* get_destination();

  /** get distance of this Participant */
  float get_distance();

  /** display details of this Participant */
  void display();

  /** get the gas money owed by this participant*/
  float get_gasmoney(float gc, int, float);

};

#endif
