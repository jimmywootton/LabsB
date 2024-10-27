#include <iostream>


using namespace std;

#include "IntVector.h"

Distance::Distance()
{
    _feet = 0;
    _inches = 0;
}

Distance::Distance(unsigned ft, double in)
{
    /*
    if (in >= 12.0)
    {
        in -= 12.0;
        ++ft;
    }
    _feet = ft;
    _inches = in;
    */
   Distance hold;
   hold._feet = ft;
   hold._inches = in;
   hold.init();
   _feet = hold._feet;
   _inches = hold._inches;
}

Distance::Distance(double in)
{
    Distance hold;
    hold._feet = 0;
    hold._inches = in;
    hold.init();
    _feet = hold._feet;
    _inches = hold._inches;
}

unsigned Distance::getFeet() const
{
    return _feet;
}

double Distance::getInches() const
{
    return _inches;
}

double Distance::distanceInInches() const
{
    return (_feet * 12) + _inches;
}

double Distance::distanceInFeet() const
{
    return _feet + (_inches/12);
}

double Distance::distanceInMeters() const
{
    return distanceInInches() * 0.0254; 
}

Distance Distance::operator+(const Distance &rhs) const
{
    Distance hold = rhs;
    hold._inches +=  _inches;
    hold._feet += _feet;
    if (hold._inches >= 12.0)
    {
        hold._inches -= 12.0;
        ++hold._feet;
    }
    
    return hold;
}

Distance Distance::operator-(const Distance &rhs) const
{
    Distance test;
    if (rhs._feet == _feet)
    {
        test._feet = 0;
        if (rhs._inches > _inches)
        {
            test._inches = rhs._inches - _inches;
        }
        else
        {
            test._inches = _inches - rhs._inches;
        }
    }
    else 
    {
        if (rhs._feet > _feet)
        {
        test._feet = rhs._feet - _feet;
        test._inches = rhs._inches - _inches;
        }
        else
        {
            test._feet = _feet - rhs._feet;
            test._inches = _inches - rhs._inches;
        }
    }
    if (test._inches < 0)
    {
        test._inches = 12 + test._inches;
        --test._feet;
    }
    return test;
}

ostream & operator<<(ostream &out, const Distance &rhs)
{
    char quote = '"';
    out << rhs._feet << "' " << rhs._inches << quote;
    return out;
}

void Distance::init()
{
    if (_inches < 0)
    {
        _inches += (_inches * -2);
    }
    
    while(_inches >= 12)
    {
        ++_feet;
        _inches -= 12;
    }
}