#ifndef MAP_H
#define MAP_H

#include <map>
#include <string>
#include <iostream>

class Map {
private:
    std::map<std::string, std::map<std::string, std::string>> locations;
    std::map<char, std::string> discoveries;
    std::string currentLocation;

public:
    Map();
    void addLocation(const std::string& locationName, const std::map<std::string, std::string>& directions);
    void addDiscovery(char direction, const std::string& description);
    bool move(const std::string& direction);
    //void setCurrentLocation(const std:: string& location);
    //void exploreDirection(char direction);
    std::string exploreDirection(char direction);
    std::string describeCurrentLocation() const;
};

#endif
