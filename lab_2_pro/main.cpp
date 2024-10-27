#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
void readData(const string& fileName, vector<double>& fpa, vector<double>& col)
{
    ifstream inFS;
    double input;
    inFS.open(fileName);
    if (!inFS.is_open())
    {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }
    while (inFS >> input)
    {
        fpa.push_back(input);
        inFS >> input;
        col.push_back(input);
    }
}







double interpolation(double targ, const vector<double>& fpa, const vector<double>& col)
{
    if (fpa.back() == targ)
    {
        return col.back();
    }
    for (unsigned int i = 0; i < fpa.size()-1;i++)
    {
        if (targ == fpa.at(i))
        {
            return col.at(i);
        }
        else if (targ > fpa.at(i) && targ < fpa.at(i+1))
        {
            double var1 = targ - fpa.at(i);
            double var2 = fpa.at(i+1) - fpa.at(i);
            double var3 = col.at(i+1) - col.at(i);
            return (var1/var2)*(var3) + col.at(i);
        }
    }
    return -99999;
}







bool isOrdered(const vector<double>& v)
{
    return (std::is_sorted(v.begin(), v.end()));
}





/*
bool isOrdered(const vector<double>& v)
{
    for (unsigned int i = 0;i < v.size()-1;i++)
    {
        if (v.at(i) > v.at(i+1))
        {
            return false;
        }
    }
    return true;
}
*/





void reorder(vector<double>& fpa, vector<double>& col)
{
    double temp;
    for (unsigned int i = 0; i < fpa.size();i++)
    {
        for (unsigned int j = i+1; j < fpa.size();++j)
        {
            if (fpa.at(j) < fpa.at(i))
            {
                temp = fpa.at(i);
                fpa.at(i) = fpa.at(j);
                fpa.at(j) = temp;
                temp = col.at(i);
                col.at(i) = col.at(j);
                col.at(j) = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) 
{
    vector<double> fpa;
    vector<double> col;
    string fileName = argv[1];
    readData(fileName, fpa, col);
    if (!isOrdered (fpa))
    {
        reorder (fpa, col);
    }
    while (true)
    {
        double targ;
        string confirm;
        cout << "Flight Path Angle:";
        cin >> targ;
        cout << interpolation (targ, fpa, col) << endl;
        cout << "Enter Another Angle?" << endl;
        cin >> confirm;
        if (confirm == "No")
        {
            return 0;
        }
    }
}

