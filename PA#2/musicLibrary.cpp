#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

const int SIZE = 100; // Global constant size of array digitalLibrary

struct songElements {
  string songID;
  string songTitle;
  string songArtist;
  double songSize;
  int songPlays;
  int songRating;
};

int arrayInfoFinder(songElements digitalLibrary[]) {

  ifstream fin; // 

  fin.open("library.txt");

  int count = 0,
    i = 0;

  while (fin >> digitalLibrary[i].songID && i < SIZE) {
    fin >> ws;
    getline(fin,digitalLibrary[i].songTitle );
    fin >> ws;
    getline(fin, digitalLibrary[i].songArtist);
    fin >> ws;
    fin >> digitalLibrary[i].songSize >> digitalLibrary[i].songPlays
        >> digitalLibrary[i].songRating;
   
    i++;  
    count++;
    }
  
  fin.close();

  return count;
}

int findIndexOfMax(songElements digitalLibrary[], int size, int start) {

 int maxIndex = start;

  for (int i = start + 1; i < size; i++) {
    if(digitalLibrary[i].songRating > digitalLibrary[maxIndex].songRating)
      maxIndex = i;
  }
  return maxIndex;
}

void ratingSelectionSort(songElements digitalLibrary[]) {
  int maxIndex,
    size;

  size = arrayInfoFinder(digitalLibrary);

  for (int index = 0; index < size - 1; index++) {
    maxIndex = findIndexOfMax(digitalLibrary, size, index);
    swap(digitalLibrary[index], digitalLibrary[maxIndex]);
  }
}

int titleAndArtistLinearSearch(songElements digitalLibrary[], string artist, string title) {

  int size = arrayInfoFinder(digitalLibrary),
    position1 = -1,
    position2 = -1;

  for (int i = 0; i < size; i++) {
    if (digitalLibrary[i].songArtist == artist) 
      position1 = i;
  }

 for (int i = 0; i < size; i++) {
    if (digitalLibrary[i].songTitle == title) 
      position2 = i;
  }

 if (position1 == position2)
   return position1;
 else
   return -1;
}

void titleBubbleSort(songElements digitalLibrary[]) {

  int size = arrayInfoFinder(digitalLibrary);
  bool swapped;

  do{ 
    swapped = false;
    for (int i = 0; i < size - 1; i++) {
      if (digitalLibrary[i].songTitle >  digitalLibrary[i+1].songTitle) {
	swap(digitalLibrary[i], digitalLibrary[i+1]);
        swapped = true;
      }
    }
  }while (swapped);
}

void idBubbleSort(songElements digitalLibrary[]) {

  int size = arrayInfoFinder(digitalLibrary);

  bool swapped;
  do{ 
    swapped = false;
    for (int i = 0; i < size - 1; i++) {
      if (digitalLibrary[i].songID > digitalLibrary[i+1].songID) {
	swap(digitalLibrary[i], digitalLibrary[i+1]);
        swapped = true;
      }
    }
  }while (swapped);
}

int idBinarySearch(songElements digitalLibrary[], string target) {
 
 int first = 0,
    size = arrayInfoFinder(digitalLibrary),
    last = size - 1,
    middle,
    position = -1;

 idBubbleSort(digitalLibrary);
 
 while (position == -1 && first <= last) {
   
   middle = (first + last) / 2;
   if (digitalLibrary[middle].songID == target)
     position = middle;
   else if (digitalLibrary[middle].songID > target)
     last = middle - 1;
   else 
     first = middle + 1;
 }
  return position;
}

void displayLibrary(songElements digitalLibrary[], int choice) {
  
  int size = arrayInfoFinder(digitalLibrary);

  if (choice == 1)
    titleBubbleSort(digitalLibrary);
  else if(choice == 2)
    ratingSelectionSort(digitalLibrary);
 
  cout << fixed << setprecision(1); 

  for(int i = 0; i < size; i++){
    cout << left << setw(30) << digitalLibrary[i].songTitle 
	 << left << setw(20) << digitalLibrary[i].songArtist
	 << right << setw(5) << digitalLibrary[i].songSize << " MB"
         << right << setw(5) << digitalLibrary[i].songPlays
         << right << setw(5) << digitalLibrary[i].songRating << endl;
  }
  cout << endl;
}

void displayLookupArtist(songElements digitalLibrary[]) {
  
  string id;
  int infoFromId;
 
  cout << "Enter the id of the song (Capital followed by 3 numbers): ";
  cin >> id;
  cout << endl;
	
  infoFromId = idBinarySearch(digitalLibrary, id);
	    
  if (infoFromId == -1)
    cout << "No song found with that ID. (Make sure letter is capital and that there are 3 numbers) \n\n";
  else
    cout << "The song with ID " << id << " is:" << endl
         << digitalLibrary[infoFromId].songTitle << " by " << endl
         << digitalLibrary[infoFromId].songArtist << endl << endl;
}

void displayLookupId(songElements digitalLibrary[]) {
  
  int infoFromLookup;
  string artist,
    title;
	
  cin.ignore();
  cout << "(Spelling and capital sensitive, refer to a displayed list of songs)" << endl
       << "Enter the Title: ";
  getline(cin, title);
  cout << "Enter the artist: ";
  getline(cin, artist);
  cout << endl;

  infoFromLookup = titleAndArtistLinearSearch(digitalLibrary, artist, title);
 
  if (infoFromLookup == -1)
    cout << "No ID found by searching for " << title << " and "
	 << artist << ".(If you're sure the song is in " 
	 << "check title, artist, and SPELLING) \n\n";
  else 
    cout << "The ID of " << digitalLibrary[infoFromLookup].songTitle << " by " 
         << digitalLibrary[infoFromLookup].songArtist << " is " 
         << digitalLibrary[infoFromLookup].songID << endl << endl;
}

int displayMenu(songElements digitalLibrary[]) {

  int choice;

  cout << "Menu \n\n"
       << "1. Display Songs sorted by title \n"
       << "2. Display Songs sorted by rating \n"
       << "3. Lookup title and artist by ID \n"
       << "4. Lookup ID by title and artist \n"
       << "5. Quick the Program \n\n"
       << "Enter your choice: ";
  cin >> choice;

  while(!cin || choice > 5) {
    cin.clear();
    cin.ignore();

    cout << "Please input a number on the menu! \n";
    cin >> choice;
  }
  return choice;
}

void mainOptions(songElements digitalLibrary[]) {
  // constant variables for options
  const int DISPLAY_TITLE = 1;
  const int DISPLAY_RATING = 2;
  const int LOOKUP_ARTIST = 3;
  const int LOOKUP_ID = 4;
  const int QUIT_MENU = 5;

  int choice;

  // Menu choices
  do {
    choice = displayMenu(digitalLibrary);
    // make me easy to follow with comments in header and body (for each)!
    if (choice != QUIT_MENU) {
      switch(choice) {
      case DISPLAY_TITLE:
	displayLibrary(digitalLibrary, choice);
	break;
      case DISPLAY_RATING:
	displayLibrary(digitalLibrary, choice);
	break;
      case LOOKUP_ARTIST:
	displayLookupArtist(digitalLibrary);
	break;
      case LOOKUP_ID:
	displayLookupId(digitalLibrary);
	break;
      }
    }
  }while(choice != QUIT_MENU);
}

int main() {

  songElements digitalLibrary[SIZE] = {{}};

  mainOptions(digitalLibrary);
}
 
