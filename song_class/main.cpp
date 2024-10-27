#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <utility>
using namespace std;

//./a.out input.txt output.txt compare.txt

class Song
{
    private:
        string original;
        string _artist;
        string _title;
        string _fullName;
        bool _onlyFullName;
    public:
        Song();
        void setAll(string a, string b, string c,string d);
        void setFullName(string a, string b);
        string getArtist() const;
        string getTitle();
        string getFullName();
        string getOg();
        bool getFullNameStatus();     
};



Song::Song()
{
    original = "NaNaN";
    _artist = "NaNaN";
    _title = "NaNaN";
    _fullName = "NaNaN";
    _onlyFullName = false;
}

void Song::setAll(string a, string b, string c, string d)
{
    _artist = a;
    _title = b;
    _fullName = c;
    original = d;
}

void Song::setFullName(string a,string b)
{
    _fullName = a;
    original = b;
    _onlyFullName = true;
}

bool Song::getFullNameStatus()
{
    return _onlyFullName;
}

string Song::getArtist() const
{
    return _artist;
}

string Song::getTitle()
{
    return _title;
}

string Song::getFullName()
{
    return _fullName;
}

string Song::getOg()
{
    return original;
}

void removeMP3(string & str)
{
    if (str.length() >= 4 && str.substr(str.length() - 4) == ".mp3") 
    {
        str.erase(str.length() - 4);
    }
}

void removeParentheses(string & str) 
{
    size_t start_pos = str.find('(');
    size_t end_pos = str.find(')');
    while (start_pos != string::npos && end_pos != string::npos && end_pos > start_pos) {
        str.erase(start_pos, end_pos - start_pos + 1);
        start_pos = str.find('(');
        end_pos = str.find(')');
    }

    start_pos = str.find('[');
    end_pos = str.find(']');
    while (start_pos != string::npos && end_pos != string::npos && end_pos > start_pos) {
        str.erase(start_pos, end_pos - start_pos + 1);
        start_pos = str.find('[');
        end_pos = str.find(']');
    }

    start_pos = str.find('{');
    end_pos = str.find('}');
    while (start_pos != string::npos && end_pos != string::npos && end_pos > start_pos) {
        str.erase(start_pos, end_pos - start_pos + 1);
        start_pos = str.find('{');
        end_pos = str.find('}');
    }
}

void removeStrings(string & s)
{
    size_t pos;
    //" outro "," intro "," shouts out "," shout out "," shouts "," shout "," skit "," mix ",
    vector <string> words = {" greatest hits "," volume "," and "," part "," remix "," click "," klick "," clique "," by "," the "," da "," ft ", " pt "," dj "," productions "," produced "," dragged "," chopped "," screwed "," production "," tha ", " family ", " mafia "," instrumental "};
    for (unsigned int i = 0;i < words.size();++i)
    {
        pos = s.find(words.at(i));
        while (pos != string::npos) 
        {
            s.erase(pos, words.at(i).size() - 1);
            pos = s.find(words.at(i), pos);
        }
    }
    words = {"vol.","ft.","pt.","☠","＂","：","⧸","？","+","!","&",":", "\"","'",".",",","?","(",")"};
    for (unsigned int i = 0;i < words.size();++i)
    {
        pos = s.find(words.at(i));
        while (pos != string::npos) 
        {
            s.erase(pos, words.at(i).size());
            pos = s.find(words.at(i), pos);
        }
    }
}

void replaceString(string& str, const string& oldStr, const string& newStr)
{
    size_t pos = 0;
    while ((pos = str.find(oldStr, pos)) != string::npos) 
    {
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
}

void makeLowerCase(string& s) 
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void addSpaces(string& str) 
{
    str = " " + str + " ";
}

void removeExtraSpaces(string& s) {
    string result;

    bool previous_space = false;
    for (char c : s) {
        if (c == ' ') {
            if (!previous_space) {
                result += c;
            }
            previous_space = true;
        }
        else {
            result += c;
            previous_space = false;
        }
    }

    s = result;
}

void trimSpaces(string& str) 
{
    // Remove spaces at the front of the string
    while (!str.empty() && str.front() == ' ') {
        str.erase(0, 1);
    }
    
    // Remove spaces at the back of the string
    while (!str.empty() && str.back() == ' ') {
        str.erase(str.length() - 1, 1);
    }
}

string simplified(string input)
{
    removeMP3(input);
    makeLowerCase(input);
    removeParentheses(input);
    addSpaces(input);
    replaceString(input,"-"," ");
    replaceString(input,"'s "," ");
    removeStrings(input);
    removeExtraSpaces(input);
    trimSpaces(input);
    if (input == " ")
    {
        input = "";
    }
    return input;
}

Song assignSongClass(string inputString)
{
    Song current;
    string delimiter = " - ";
    size_t delimiterPosition = inputString.find(delimiter);
    if (delimiterPosition == string::npos) 
    {
        current.setFullName(simplified(inputString), inputString);
    }
    else
    {
        string artist = simplified(inputString.substr(0, delimiterPosition));
        string title = simplified(inputString.substr(delimiterPosition + delimiter.length()));
        string total = artist + " " + title;
        current.setAll(artist, title, total, inputString);
    }
    return current;
}

void rewriteTxt(string a, string b, string c)
{
    ifstream inputFromInputFS;
    ofstream outputToOutputFS;
    inputFromInputFS.open(a);
    outputToOutputFS.open(b);
    string name;
    vector <string> inputTxt;
    vector <string> outputTxt;
    vector <string> outputReplaceTxt;
    while (getline(inputFromInputFS, name))
    {
        inputTxt.push_back(name);
        if (name.find(" - ") == string::npos)
        {
            outputToOutputFS << name << endl;
            outputTxt.push_back(name);
        }
    }
    cout << "Ready?" << endl;
    cin.get();
    ofstream outputToInputFS;
    ifstream inputFromOutputFS;
    ofstream outputToCompareFS;
    outputToInputFS.open(a);
    inputFromOutputFS.open(b);
    outputToCompareFS.open(c);
    while (getline(inputFromOutputFS,name))
    {
        outputReplaceTxt.push_back(name);
    }
    if (outputTxt.size() == 0)
    {
        for (unsigned int i = 0;i < inputTxt.size();++i)
        {
            outputToInputFS << inputTxt.at(i) << endl;
        }
    }
    else
    {
        int j = 0;
        for (unsigned int i = 0;i < inputTxt.size();++i)
        {
            if (inputTxt.at(i) == outputTxt.at(j))
            {
                outputToInputFS << outputReplaceTxt.at(j) << endl;
                if (j < outputReplaceTxt.size() - 1)
                {
                    ++j;
                }
            }
            else
            {
                outputToInputFS << inputTxt.at(i) << endl;
            }
        }
    }
    inputFromInputFS.clear();
    inputFromInputFS.seekg(0, ios::beg);
}

int damerauLevenshtein(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    vector<vector<int>> d(len1 + 1, vector<int>(len2 + 1));
    for (int i = 0; i <= len1; ++i) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; ++j) {
        d[0][j] = j;
    }
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min({d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost});
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                d[i][j] = min(d[i][j], d[i - 2][j - 2] + cost);
            }
        }
    }
    return d[len1][len2];
}

int updated_levenshtein(string longerstr, string shorterstr)
{
    if (shorterstr.size() > longerstr.size())
    {
        swap(longerstr, shorterstr);
    }
    int i  = shorterstr.size();
    string temp;
    vector<int> levenval;
    for (int j = 0; j <= longerstr.size() - i; j++) 
    {
        temp = longerstr.substr(j, i);
        levenval.push_back(damerauLevenshtein(temp,shorterstr));
    }
    return *min_element(levenval.begin(),levenval.end());
}

void sortAndRemoveDuplicates(vector<int>& v) 
{
    sort(v.begin(), v.end());
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());
}

void minimizeVec(vector<Song>& newV, vector<int>& temp)
{
    sortAndRemoveDuplicates(temp);
    for (unsigned int i = 0;i < temp.size();i++)
    {
        newV.erase(newV.begin() + temp.at(i));
        for (unsigned int j = i+1;j < temp.size();++j)
        {
            temp.at(j) -= 1;
        }
    }
}
/*
bool compare_songs(const Song& song1,const  Song& song2) 
{
    return song1.getArtist().size() < song2.getArtist().size();
}
*/
int main(int argc, char *argv[]) 
{
    char* str1 = argv[1];
    char* str2 = argv[2];
    char* str3 = argv[3];
    rewriteTxt(str1,str2,str3);
    ifstream inFS;
    ofstream outFS;
    inFS.open(argv[1]);
    outFS.open(argv[3]);
    string name;
    vector <Song> playlist;
    vector <Song> extra;
    while (getline(inFS,name))
    {
        Song current = assignSongClass(name);
        if (current.getTitle() == "" || current.getArtist() == "")
        {
            
            extra.push_back(current);
        }
        else
        {
            playlist.push_back(current);
        }
    }

    for (unsigned int s = 0;s < 1;++s)
    {
        outFS << s << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
        vector <int> temp;
        for (int i = 0; i < playlist.size(); i++) 
        {
            for (int j = i + 1; j < playlist.size(); j++) 
            {
                if (!((playlist.at(i).getTitle() == "intro" && playlist.at(j).getTitle() == "outro") || (playlist.at(i).getTitle() == "outro" && playlist.at(j).getTitle() == "intro")))
                {
                    if (playlist.at(i).getFullNameStatus() == true || playlist.at(j).getFullNameStatus() == true)
                    {
                        if (updated_levenshtein(playlist.at(i).getFullName(), playlist.at(j).getFullName()) <= s)
                        {
                            outFS << playlist.at(i).getOg() << endl;
                            outFS << playlist.at(j).getOg() << endl << endl;
                            temp.push_back(i);
                            temp.push_back(j);
                        }
                    }
                    else
                    {
                        
                        if (updated_levenshtein(playlist.at(i).getTitle(), playlist.at(j).getTitle()) <= s  &&  updated_levenshtein(playlist.at(i).getArtist(), playlist.at(j).getArtist()) <= s  )
                        {
                            outFS << playlist.at(i).getOg() << endl;
                            outFS << playlist.at(j).getOg() << endl << endl;
                            temp.push_back(i);
                            temp.push_back(j);
                        }
                        
                    }
                }        
            }
        }
        minimizeVec(playlist, temp);
    }
    
}

