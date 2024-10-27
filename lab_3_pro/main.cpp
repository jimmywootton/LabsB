#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Date {
private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

public:
   Date();
   Date(unsigned m, unsigned d, unsigned y);
   Date(const string &mn, unsigned d, unsigned y);
   void printNumeric() const;
   void printAlpha() const;
private:
   bool isLeap(unsigned y) const;
   unsigned daysPerMonth(unsigned m, unsigned y) const;
   string name(unsigned m) const;
   unsigned number(const string &mn) const;
   string toCap(const string &mn);
   bool notNorm(unsigned m,unsigned d, unsigned y);
};

bool Date::notNorm(unsigned m,unsigned d, unsigned y)
{
   if (m < 1 || m > 12)
   {
      return true;
   }
   if (d < 1 || d > daysPerMonth(m,y))
   {
      return true;
   }
   return false;
}

string Date::toCap(const string &mn)
{
   string capMn = mn;
   if (islower(mn.at(0)))
   {
      capMn.at(0) = toupper(mn.at(0));
   }
   return capMn;
}

Date::Date()
{
   day = 1;
   month = 1;
   monthName = "January";
   year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
   if (notNorm(m,d,y))
   {
      if (m < 1)
      {
         month = 1;
      }
      else if (m > 12)
      {
         month = 12;
      }
      else
      {
         month = m;
      }
      if (d < 1)
      {
         day = 1;
      }
      else if (d > daysPerMonth(month,y))
      {
         day = daysPerMonth(month,y);
      }
      else
      {
         day = d;
      }
      monthName = name(month);
      year = y;
      cout << "Invalid date values: Date corrected to ";
      printNumeric();
      cout << "." << endl;
   }
   else
   {
      month = m;
      day = d;
      monthName = name(month);
      year = y;
   }
}

Date::Date(const string &mn, unsigned d, unsigned y)
{
   if (number(toCap(mn)) == 13)
   {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      day = 1;
      month = 1;
      monthName = "January";
      year = 2000;
   }
   else
   {
      if (notNorm(number(toCap(mn)),d,y))
      {
         if (d < 1)
         {
            day = 1;
         }
         else if (d > daysPerMonth(number(toCap(mn)),y))
         {
            day = daysPerMonth(number(toCap(mn)),y);
         }
         else
         {
            day = d;
         }
         month = number(toCap(mn));
         monthName = toCap(mn);
         year = y;
         cout << "Invalid date values: Date corrected to ";
         printNumeric();
         cout << "." << endl;
      }
      else
      {
         day = d;
         month = number(toCap(mn));
         monthName = toCap(mn);
         year = y;
      }
   }
}

void Date::printNumeric() const
{
   cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const
{
   cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const
{
   bool isLeapYear = false;
   if (y % 4 == 0) {
      if (y % 100 == 0) {
         if (y % 400 == 0) {
            isLeapYear = true;
         }
      } 
      else isLeapYear = true;
   }
   return isLeapYear;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
   if (m == 2)
   {
      if(isLeap(y))
      {
         return 29;
      }
      else
      {
         return 28;
      }
   }
   else if (m == 1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
   {
      return 31;
   }
   else
   {
      return 30;
   }
}

string Date::name(unsigned m) const
{
   if (m == 1) 
   {
      return "January";
   }
   else if (m == 2)
   {
      return "February";
   }
   else if (m == 3)
   {
      return "March";
   }
   else if (m == 4)
   {
      return "April";
   }
   else if (m == 5)
   {
      return "May";
   }
   else if (m == 6)
   {
      return "June";
   }
   else if (m == 7)
   {
      return "July";
   }
   else if (m == 8)
   {
      return "August";
   }
   else if (m == 9)
   {
      return "September";
   }
   else if (m == 10)
   {
      return "October";
   }
   else if (m == 11)
   {
      return "November";
   }
   else
   {
      return "December";
   }
}

unsigned Date::number(const string &mn) const
{ 
   if (mn == "January")
   {
      return 1;
   }
   else if (mn == "February")
   {
      return 2;
   }
   else if (mn == "March")
   {
      return 3;
   }
   else if (mn == "April")
   {
      return 4;
   }
   else if (mn== "May")
   {
      return 5;
   }
   else if (mn == "June")
   {
      return 6;
   }
   else if (mn == "July")
   {
      return 7;
   }
   else if (mn == "August")
   {
      return 8;
   }
   else if (mn == "September")
   {
      return 9;
   }
   else if (mn == "October")
   {
      return 10;
   }
   else if (mn == "November")
   {
      return 11;
   }
   else if (mn == "December")
   {
      return 12;
   }
   else
   {
      return 13;
   }
}

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
