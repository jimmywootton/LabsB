#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   int input;
   ifstream inFS;
   ofstream outFS;
   inFS.open(argv[1]);
   outFS.open(argv[2]);
   vector<int> v;
   char trash;
   while (inFS >> input)
   {
      v.push_back(input);
      inFS >> trash;
   }

   int sum = 0;
   for (unsigned int i = 0;i < v.size();i++)
   {
      sum += v.at(i);
   }
   int avg = sum / v.size();
   for (unsigned int i = 0;i < v.size();i++)
   {
      v.at(i) -= avg;
   }
   outFS << v.at(0);
   for (unsigned int i = 1;i < v.size();i++)
   {
      outFS << "," << v.at(i);
   }

   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   
   // Create input stream and open input csv file.
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   
   // Read in integers from input file to vector.
   
   // Close input stream.
   
   // Get integer average of all values read in.
   
   // Convert each value within vector to be the difference between the original value and the average.
   
   // Create output stream and open/create output csv file.

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   
   // Close output stream.
   
   return 0;
}