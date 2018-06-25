#ifndef _SONG_H_
#define _SONG_H_

/** Represents a Song */
class Song {
  char* title; /** title for this song*/
  char* album; /** album of this song */
  char* artist; /** artist for this song*/

  /** dynamically copies the string  
      @param str string to be copied*/
  char* copystring(const char* str); 
 public:

  /** 3-argument constructor
      @param t title of this song
      @param art artist of this song
      @param alb album of this song*/
  Song(const char *t, const char* art, const char *alb);

  Song();

  /** Destructor */
  ~Song();

  /** set title for this song
      @param t title to be set*/
  void set_title(const char* t);

  /** set artist for this Song
      @param art artist to be set*/
  void set_artist(const char* art);

  /** set album for this song
      @param alb album to be set*/
  void set_album(const char* alb);

  /** get title of this Song */
  char* get_title();	

  /** get artist of this song */
  char* get_artist();

  /** get album of this song */
  char * get_album();

  /** print details of the song */
  void display();
};

#endif
