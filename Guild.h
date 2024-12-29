#ifndef __GUILD_H__
#define __GUILD_H__

#include <iostream>
#include "Location.h"
#include "Character.h"
#include "Wizard.h"
#include "Knight.h"

class Guild : public Location {
public:
    Guild();
    void enter(Character* player) override;
};

#endif // __GUILD_H__
