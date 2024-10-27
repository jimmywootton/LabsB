#ifndef WIZARD_H
#define WIZARD_H
using namespace std;

#include <iostream>
#include "Character.h"

class Wizard : public Character {    
    protected:       
        int rank;   
    public:
        Wizard(const string &name, double health, double attackStrength, int rank);   
        void attack(Character &);
};

#endif
