#include "Location.h"

Location::Location(const std::string& name, const std::string& desc)
    : area_name(name), description(desc) {}

std::string Location::getAreaName() const {
    return area_name;
}

std::string Location::getDescription() const {
    return description;
}

Location::~Location() = default;
