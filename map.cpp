#include "map.h"
#include <iostream>

Map::Map() : currentLocation("start") {}

void Map::addLocation(const std::string& locationName, const std::map<std::string, std::string>& directions) {
    locations[locationName] = directions;
}

void Map::addDiscovery(char direction, const std::string& description) {
    discoveries[direction] = description;
}

bool Map::move(const std::string& direction) {
    auto& directions = locations[currentLocation];
    auto it = directions.find(direction);
    if (it != directions.end()) {
        currentLocation = it->second;
        return true;
    }
    return false;
}

std::string Map::exploreDirection(char direction) {
    auto search = discoveries.find(direction);
    if (search != discoveries.end()) {
        return search->second;
    }
    return "You have found nothing. Keep walking.";
}

std::string Map::describeCurrentLocation() const {
    return "You are currently at " + currentLocation + ".";
}
