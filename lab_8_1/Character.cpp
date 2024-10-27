#include "Character.h"

#include <iostream>

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength) 
: type(type), name(name), health(health), attackStrength(attackStrength){}

HeroType Character::getType() const 
{
    return type;
}

const string & Character::getName() const 
{
    return name;
}

int Character::getHealth() const 
{
    return health;
}


void Character::damage(double d)
{
    health -= d;
}

bool Character::isAlive() const 
{
    if (this->health <= 0) 
    {
        return false;
    }
    return true;
}