#include <string>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

enum HeroType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
	HeroType type;
	string name;
	double health;
	double attackStrength;

 public:
 	Character(HeroType, const string &, double, double);
 	HeroType getType() const;
 	const string & getName() const;
 	int getHealth() const;
 	void damage(double d);
 	bool isAlive() const;
 	virtual void attack(Character &) = 0;
 };

#endif