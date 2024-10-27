#ifndef WARRIOR_H
#define WARRIOR_H

using namespace std;
#include <iostream>
#include "Character.h"


class Warrior : public Character 
{
    private:  
        string allegiance;
    public:
        Warrior(const string &name, double health, double attackStrength, string org);
        void attack(Character &);
};

#endif
