#include <iostream>
#include <cstring>
#include <vector>
#include "videogames.h"
#include "music.h"
#include "movies.h"

using namespace std;

void ADD(vector<media*> &vect);

int main() {
  vector<media*> mediaVect;
  bool running = true;

  while (running) {
    cout << "Type ADD, SEARCH, DELETE, or QUIT" << endl << "> ";
    //read in an input
    char action[10];
    cin.get(action, 11);
    cin.get();
    if (strcmp(action, "ADD") == 0) {
      ADD(mediaVect);
    } else if (strcmp(action, "SEARCH") == 0) {
      //ask for search by year or title, then look
    } else if (strcmp(action, "DELETE") == 0) {
      //use search functionality, then have a confirmation to delete
    } else if (strcmp(action, "QUIT") == 0) {
      //quit program
      cout << "Program terminated";
      return 0;
    }
  }
  return 0;
}

void ADD(vector<media*> &vect) {
  //ask what media, then add to vect
  cout << "What kind of media? VIDEOGAMES, MUSIC, MOVIES" << endl << "> ";
  char whatMedia[20];
  cin.get(whatMedia, 21);
  cin.get();
  if (strcmp(whatMedia, "VIDEOGAMES") == 0) {
    char* tempTitle[80];
    int tempYear;
    char* tempPub[80];
    int tempRating;
    cout << "Enter the title" << endl << "> ";
    cin.get(*tempTitle, 81);
    cin.get();
    cout << "Enter the year of release" << endl << "> ";
    cin >> tempYear;
    cin.ignore();
    cout << "Enter the name of the publisher" << endl << "> ";
    cin.get(*tempPub, 81);
    cin.get();
    cout << "Enter the rating" << endl << "> ";
    cin >> tempRating;
    cin.ignore();
    videogames* tempVideogame = new videogames(tempTitle, tempYear, tempPub, tempRating);
    vect.pushback(tempVideogame);
    cout << vect[0]->tempTitle;
  }
}
