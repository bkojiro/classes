#include <iostream>
#include <cstring>
#include <vector>
#include "videogames.h"
#include "music.h"
#include "movies.h"

using namespace std;

void ADD(vector<media*> &vect);
void SEARCH(vector<media*> vect);
void DELETE(vector<media*> &vect);

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
      //ask what kind of media then add with specs
      ADD(mediaVect);
    } else if (strcmp(action, "SEARCH") == 0) {
      //ask for search by year or title, then look
      SEARCH(mediaVect);
    } else if (strcmp(action, "DELETE") == 0) {
      //use search functionality, then have a confirmation to delete
      DELETE(mediaVect);
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
    cout << "Enter the duration of the movie (hour:min)" << endl << "> ";
    cin.get(tempMovie->duration, 21);
    cin.get();
    cout << "Enter the rating" << endl << "> ";
    cin >> tempMovie->rating;
    cin.ignore();
    vect.push_back(tempMovie);
  }
}

void SEARCH(vector<media*> vect) {
//ask for title or year
  cout << "Search by TITLE or YEAR?" << endl << "> ";
  char titleOrYear[20];
  cin.get(titleOrYear, 21);
  cin.get();
  if (strcmp(titleOrYear, "TITLE") == 0) { //search by title
    cout << "Search for what title?" << endl << "> ";
    char whatTitle[80];
    cin.get(whatTitle, 81);
    cin.get();
    vector<media*>::iterator iter;
    for (iter = vect.begin(); iter < vect.end(); iter++) {
      if (strcmp((*iter)->getTitle(), whatTitle) == 0) {
        (*iter)->printInfo();
      }
    }
  } else if (strcmp(titleOrYear, "YEAR") == 0) { //search by year
    cout << "Search for what year?" << endl << "> ";
    int whatYear;
    cin >> whatYear;
    cin.ignore();
    vector<media*>::iterator iter;
    for (iter = vect.begin(); iter < vect.end(); iter++) {
      if ((*iter)->getYear() == whatYear) {
        (*iter)->printInfo();
      }
    }
  }
}


void DELETE(vector<media*> &vect) { //make sure to delete DATA
  //ask for title or year
  cout << "Search by TITLE or YEAR?" << endl << "> ";
  char titleOrYear[20];
  cin.get(titleOrYear, 21);
  cin.get();
  int count = 1;
  vector<media*> deleteVect;
  //make a numbered list of all entries that follow criteria, then save them in a new vect
  if (strcmp(titleOrYear, "TITLE") == 0) { //search by title
    cout << "Search for what title?" << endl << "> ";
    char whatTitle[80];
    cin.get(whatTitle, 81);
    cin.get();
    vector<media*>::iterator iter;
    for (iter = vect.begin(); iter < vect.end(); iter++) {
      if (strcmp((*iter)->getTitle(), whatTitle) == 0) {
	cout << count << ") ";
	(*iter)->printInfo();
	count++; //MAKE A NEW VECT!!!!
	deleteVect.push_back(*iter);
      }
    }
  } else if (strcmp(titleOrYear, "YEAR") == 0) { //search by year
    cout << "Search for what year?" << endl << "> ";
    int whatYear;
    cin >> whatYear;
    cin.ignore();
    vector<media*>::iterator iter;
    for (iter = vect.begin(); iter < vect.end(); iter++) {
      if ((*iter)->getYear() == whatYear) {
	cout << count << ") ";
        (*iter)->printInfo();
	count++;
	deleteVect.push_back(*iter);
      }
    }
  }
  cout << endl << "Select the number you would like to delete" << endl << "> ";
  int deleteNum = 0;
  cin >> deleteNum;
  cin.ignore();
  //confirmation
  cout << "Are you sure you would like to delete " << deleteVect[deleteNum-1]->getTitle() << " (" << deleteVect[deleteNum-1]->getYear() << ") ? Enter y or n" << endl << "> ";
  char confirm;
  cin >> confirm;
  cin.ignore();
  if (confirm == 'y') {
    vector<media*>::iterator iter;
    for (iter = vect.begin(); iter < vect.end(); iter++) {
      if (deleteVect[deleteNum-1] == (*iter)) {
	//delete data too!
	delete *iter;
	vect.erase(iter);
	return;
      }
    }
  } else {
    cout << "Deletion canceled" << endl;
  }
}
