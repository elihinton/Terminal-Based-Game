#ifndef __ARENA_H__
#define __ARENA_H__

#include "Location.h"
#include "Character.h"
#include "Enemy.h"

class Arena : public Location {
public:
    Arena(const std::string& name, const std::string& desc);
    void enter(Character* player) override;
    void battle(Character* player, Enemy* enemy);
    ~Arena();
};

#endif // __ARENA_H__
