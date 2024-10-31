#include <iostream>
#include "media.h"

using namespace std;

media::media() {
  title = new char[80];
  year = 0;
}

char* media::getTitle() {
  return title;
}

int media::getYear() {
  return year;
}

void media::printInfo() {
  cout << getTitle() << ", " << getYear() << endl;
}
