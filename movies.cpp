#include <iostream>
#include "movies.h"

using namespace std;

movies::movies() {
  director = new char[80];
  duration = new char[20];
  rating = 0;
}

char* movies::getDirector() {
  return director;
}

char* movies::getDuration() {
  return duration;
}

int movies::getRating() {
  return rating;
}

void movies::printInfo() {
  cout << getTitle() << " (" << getDuration() << ") by director " << getDirector() << ", released " << getYear() << ", " << getRating() << " stars" << endl;
}
