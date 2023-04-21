#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <set>

class AudioTrack {
public:
  AudioTrack(const std::string& title, const std::string& artist, int duration);
  const std::string& getTitle() const;
  const std::string& getArtist() const;
  int getDuration() const;
  void setTitle(const std::string& title);
  void setArtist(const std::string& artist);
  void setDuration(int duration);
  
private:
  std::string title_;
  std::string artist_;
  int duration_; // Duration in seconds
};

class TrackNode {
public:
  explicit TrackNode(const AudioTrack& track);
  const AudioTrack& getTrack() const;
  bool operator<(const TrackNode& other) const;
  
private:
  AudioTrack track_; // Holds the AudioTrack object
};

class TrackLibrary {
public:
  void addTrack(const AudioTrack& track);
  bool removeTrackByTitle(const std::string& title);
  std::vector<AudioTrack> searchByArtist (const std::string& artist)
  
private:
  std::map<std::string, std::list<TrackNode>> hashMap;
  std::set<TrackNode> balancedBST;
  std::list<TrackNode>::iterator findNodeInList(std::list<TrackNode>& nodeList, const AudioTrack& track);
};

#endif
