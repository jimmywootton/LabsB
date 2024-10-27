#include <iostream>
using namespace std;

class Distance {

 public:

   
   Distance();


   
   Distance(unsigned ft, double in);


   
   Distance(double in);


   
   unsigned getFeet() const;


   
   double getInches() const;


   
   double distanceInInches() const;


   
   double distanceInFeet() const;


   
   double distanceInMeters() const;


   
   Distance operator+(const Distance &rhs) const;


   
   Distance operator-(const Distance &rhs) const;

  string test();
   
   friend ostream & operator<<(ostream &out, const Distance &rhs);

 private:

   
   void init();

   string _test;
    

   unsigned _feet;
   double _inches;    
    
};
