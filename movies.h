#include <iostream>
#include "media.h"

using namespace std;

class movies : public media {
 public:
  movies();
  char* director;
  char* duration;
  int rating;
  char* getDirector();
  char* getDuration();
  int getRating();
  virtual void printInfo();
};
