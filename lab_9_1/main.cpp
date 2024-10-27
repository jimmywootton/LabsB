#include <iostream>
#include <string>

using namespace std;


void flipString(string &s)
{
   if (s.size() <= 1)
   {
      return;
   }
   char last = s.back();
   s.pop_back();
   flipString(s);
   s = last + s;
}

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here


