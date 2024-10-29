#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include "media.h"

using namespace std;

class music : public media {
 public:
  music();
  char* artist;
  char* duration; //so I can store a value like "1:26"
  char* publisher;
  char* getArtist();
  char* getDuration();
  char* getPublisher();
};

#endif
