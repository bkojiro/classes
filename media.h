#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

using namespace std;

class media {
 public:
  media();
  char* title;
  int year;
  char* getTitle();
  int getYear();
  virtual void printInfo();
};

#endif
