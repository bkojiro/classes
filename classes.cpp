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
    videogames* tempVideogame = new videogames();
    cout << "Enter the title" << endl << "> ";
    cin.get(tempVideogame->title, 81);
    cin.get();
    cout << "Enter the year of release" << endl << "> ";
    cin >> tempVideogame->year;
    cin.ignore();
    cout << "Enter the name of the publisher" << endl << "> ";
    cin.get(tempVideogame->publisher, 81);
    cin.get();
    cout << "Enter the rating" << endl << "> ";
    cin >> tempVideogame->rating;
    cin.ignore();
    vect.push_back(tempVideogame);
  } else if (strcmp(whatMedia, "MUSIC") == 0) {
    music* tempMusic = new music();
    cout << "Enter the name" << endl << "> ";
    cin.get(tempMusic->title, 81);
    cin.get();
    cout << "Enter the year of release" << endl << "> ";
    cin >> tempMusic->year;
    cin.ignore();
    cout << "Enter the artist" << endl << "> ";
    cin.get(tempMusic->artist, 81);
    cin.get();
    cout << "Enter the duration (min:secs)" << endl << "> ";
    cin.get(tempMusic->duration, 21);
    cin.get();
    cout << "Enter the name of the publisher" << endl << "> ";
    cin.get(tempMusic->publisher, 81);
    cin.get();
    vect.push_back(tempMusic);
  } else if (strcmp(whatMedia, "MOVIES") == 0) {
    movies* tempMovie = new movies();
    cout << "Enter the title" << endl << "> ";
    cin.get(tempMovie->title, 81);
    cin.get();
    cout << "Enter the year of release" << endl << "> ";
    cin >> tempMovie->year;
    cin.ignore();
    cout << "Enter the name of the director" << endl << "> ";
    cin.get(tempMovie->director, 81);
    cin.get();
    cout << "Enter the duration of the movie" << endl << "> ";
    cin.get(tempMovie->duration, 21);
    cin.get();
    cout << "Enter the rating" << endl << "> ";
    cin >> tempVideogame->rating;
    cin.ignore();
    vect.push_back(tempMovie);
  }
}
