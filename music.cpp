#include <iostream>
#include "music.h"

using namespace std;

music::music() {
  artist = new char[80];
  duration = new char[20];
  publisher = new char[80];
}

char* music::getArtist() {
  return artist;
}

char* music::getDuration() {
  return duration;
}

char* music:: getPublisher() {
  return publisher;
}
