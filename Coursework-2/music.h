#ifndef _MUSICH
#define _MUSICH

#include <string>
#include <list>
#include <set>
#include <map>

class AudioTrack {
public:
    AudioTrack(const std::string& title, const std::string& artist, int duration);

    const std::string& getArtist() const;
    const std::string& getTitle() const;
    int getDuration() const;

    void setArtist(const std::string& artist);
    void setTitle(const std::string& title);
    void setDuration(int duration);

private:
    std::string title;
    std::string artist;
    int duration;
};

class TrackNode {
public:
    explicit TrackNode(const AudioTrack& track);

    const AudioTrack& getTrack() const;

    bool operator<(const TrackNode& other) const;

private:
    AudioTrack track;
};

class TrackLibrary {
public:
    void addTrack(const AudioTrack& track);
    void removeTrack(const AudioTrack& track);
    std::list<TrackNode> searchByArtist(const std::string& artist);

private:
    std::map<std::string, std::list<TrackNode>> hashMap;
    std::set<TrackNode> balancedBST;

    std::list<TrackNode>::iterator findNodeInList(std::list<TrackNode>& nodeList, const AudioTrack& track);
};

#endif
