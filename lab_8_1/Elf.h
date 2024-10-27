#ifndef ELF_H
#define ELF_H

using namespace std;
#include <iostream>
#include "Character.h"
class Elf : public Character 
{ 
    private:
        string family;
    public:
        Elf(const string &name, double health, double attackStrength, string org);
        void attack(Character &);
};
#endif
