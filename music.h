#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <string>
#include <list>
#include <set>
#include <map>

class TrackLibrary
{
 private:
  Dictionary<String, List<TrackNode>> hashTable;
  Dictionary<List<Tracknode>> artistHashTable;
  BalancedBinarySearchTree<TrackNode> balancedBST;
  
 public:
  void addTrack(AudioTrack track);
  void removeTrack(AudioTrack track);
  Track searchByArtist(AudioString artist);
}

class AudioTrack
{
 private:
  const std::string& title;
  const std::string& artist;
  int duration;

public:
  AudioTrack(const std::string& name, const std::string& artist, int duration);

  const std::string& getArtist();
  const std::string& getTitle();
  int getDuration();

  void setArtist(const std::string& artist);
  void setTitle(const std::string& title);
  void setDuration(int duration);
}

class TrackNode
{

}

#endif
