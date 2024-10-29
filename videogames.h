#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class videogames : public media {
 public:
  videogames();
  char* getPublisher();
  int getRating();
  char* publisher;
  int rating;
};

#endif
