#include <iostream>
#include "videogames.h"
#include <cstring>

using namespace std;

videogames::videogames() {
  publisher = new char[80];
  rating = 0;
}

char* videogames::getPublisher() {
  return publisher;
}

int videogames::getRating() {
  return rating;
}

void videogames::printInfo() {
  cout << getTitle() << ", released " << getYear() << " by " << getPublisher() << ", rated " << getRating() << " stars" << endl;
}
