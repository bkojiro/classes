#include <iostream>
#include "videogames.h"
#include <cstring>

using namespace std;

videogames::videogames() {
  title = new char[80];
  year = 0;
  publisher = new char[80];
  rating = 0;
}

videogames::videogames (char* newTitle, int newYear, char* newPub, int newRating){
  title = new char[80];
  strcpy(title, newTitle);
  year = newYear;
  publisher = new char[80];
  strcpy(publisher, newPub);
  rating = newRating;
}

char* videogames::getTitle() {
  return title;
}

int videogames::getYear() {
  return year;
}

char* videogames::getPublisher() {
  return publisher;
}

int videogames::getRating() {
  return rating;
}
