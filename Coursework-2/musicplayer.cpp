#include "music.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void addMultipleTracks(TrackLibrary &library, const std::string &filename)
{
    std::ifstream source_file;
    source_file.open(filename);
    if (!source_file) {
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
        if (!(std::getline(iss, title, '\t') && std::getline(iss, artist, '\t') && (iss >> duration))) {
            std::cout << "Error: Invalid input on line " << lineCount << std::endl;
        } else {
	  AudioTrack track(title, artist, "", 0, duration);
	  library.addTrack(track);
            std::cout << "Files successfully loaded";
        }
    }
}

int main()
{

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

            std::string filename;
            std::cout << "Enter the filename to load tracks from: ";
            std::cin >> filename;
            addMultipleTracks(library, filename);

        } else if (option == 's') {
        } else if (option == 'e') {
        } else if (option == 'r') {
            std::string title;
            std::cout << "Enter the title of the track to remove: ";
            std::cin.ignore();
            std::getline(std::cin, title);

            if (library.removeTrackByTitle(title)) {
                std::cout << "Track removed.\n";
            } else {
                std::cout << "Track not found.\n";
            }
        } else if (option != 'p') {
            std::cout << "Invalid option. Please enter s, e, r, a, or p\n";
        }

    } while (option != 'p');

    std::cout << "Exiting...\n";

    return 0;
}
