#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include "Song.h"
#include "trip.h"

/** Represents a Playlist */
class Playlist{
  int count;
  static int DEFAULT_SIZE;
  char *name; /**< name for this Playlist */
  char *author; /**< author for this Playlist */
 public:
  Song *playlist; /**< array of songs for this playlist */
  /** Deafault constructor */
  Playlist();
  /** 2-argument constructor
      @param n Name for this Playlist 
      @param a author for this Playlist */
  Playlist(const char *n, const char* a);
  /** set the name for this Playlist
      @param n Name for this Playlist */
  void set_name(const char *n);
  /** get the name for this Playlist
      @return the name of this Playlist */
  char *get_name();
  /** set the author for this Playlist 
      @param a author for this Playlist */
  void set_author(const char *a);
  /** get the author for this Playlist
      @return the author for this Playlist */
  char *get_author();
  /** set the count for this Playlist
      @param c count for this Playlist*/
  void set_count(int);
  /** get the count for this Playlist
      @return the count for this Playlist */
  int get_count();
  /** adds a song to the playlist array
      @param s a Song */
  void add_Song(const Song &s);
  ~Playlist();
  char *makeString(const char*str);
  /** adds a song to the playlist*/
  void add_song(const Song &p);
  /** displays the detail of the playlist */
  void display();
  /**displays the songs in the playlist*/
  void display_song();
};
#endif
