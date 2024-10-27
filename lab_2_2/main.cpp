#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(string filename, char ch)
{
    ifstream inFS;
    inFS.open(filename);
    char alpha;
    int count = 0;
    if (!inFS.is_open())
    {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    while (inFS.get(alpha))
    {
        if (alpha == ch)
            {
                ++count;
            }
    }
    inFS.close();
    
    return count;
}


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
