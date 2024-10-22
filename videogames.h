#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class videogames : public media {
 public:
  videogames();
  videogames(char* newTitle, int newYear, char* newPub, int newRating);
  char* getTitle();
  int getYear();
  char* getPublisher();
  int getRating();
 private:
  char* title;
  int year;
  char* publisher;
  int rating;
};
