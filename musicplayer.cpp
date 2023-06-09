#include "music.h"
#include "music.cpp"
#include <iostream>
#include <fstream>
#include <string>

int main(){

  TrackLibrary library;
  char option;
  do {
    
    std::cout << "\n******** Menu ********\n";
    std::cout << "s : save tracks in the library to a file\n";
    std::cout << "e : search by artist/band name\n";
    std::cout << "r : remove specific track(s)\n";
    std::cout << "a : Add all tracks from a file\n";
    std::cout << "p : exit program\n";
    std::cout << "select an option from above: ";
    std::cin >> option;

    if (option == 'a') {

    }else if (option == 's') {
    }else if (option == 'e') {
    }else if (option == 'r') {
    }else if (option == 'a') {
    }else if (option != 'p') {
      std::cout << "Invalid option. Please enter s, e, r, a, or p\n";
    }

  } while (option != 'p');

  std::cout << "Exiting...\n";

  return 0;
}

void addTracks(std::string filename)
{
  std::ifstream source_file;
  source_file.open(filename);
  if(!source_file) {
    std::cout << "Error: Couldn't open source file.\n";
  }
  
  std::string line;
  int lineCount;
  while (std::getline(source_file, line))
  {
    ++lineCount;
    std::istringstream iss(line);
    std::string title, artist;
    int duration;
    if (!(iss >> title >> artist >> duration)) {
      std::cout << "Error: Invalid input on line " << lineCount << std::endl;
    } else {
      library.addTrack(title, artist, duration);
      std::cout << "Files successfully loaded";
    }
  }
}
