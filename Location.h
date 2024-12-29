#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <string>
#include "Character.h"

using namespace std;

class Location {
protected:
    string area_name;
    string description;

public:
    Location(const string& name, const string& desc);
    virtual void enter(Character* player) = 0;
    string getAreaName() const;
    string getDescription() const;
    virtual ~Location();
};

#endif // __LOCATION_H__
