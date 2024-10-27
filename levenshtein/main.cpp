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

void makeLowerCase(string& s) 
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
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

void removeSpecialCharacters(string& s) {
    string result;

    for (char c : s) {
        if (!(c == '+' || c == '!' || c == '&' || c == ':' ||  c == '\'' || c == '"'  || c == '.' || c == ',' || c == '?'))
        {
            result += c;
        }
    }

    s = result;
}



void removeAnd(string& s) {
    size_t pos = s.find(" and ");
    while (pos != string::npos) {
        s.erase(pos, 4);
        pos = s.find(" and ", pos);
    }

    pos = s.find(" ft ");
    while (pos != string::npos) {
        s.erase(pos, 3);
        pos = s.find(" ft ", pos);
    }

    pos = s.find(" pt. ");
    while (pos != string::npos) {
        s.erase(pos, 3);
        pos = s.find(" pt ", pos);
    }

    pos = s.find(" part ");
    while (pos != string::npos) {
        s.erase(pos, 5);
        pos = s.find(" part ", pos);
    }

    pos = s.find(" mix ");
    while (pos != string::npos) {
        s.erase(pos, 4);
        pos = s.find(" mix ", pos);
    }

    pos = s.find(" remix ");
    while (pos != string::npos) {
        s.erase(pos, 6);
        pos = s.find(" remix ", pos);
    }

    pos = s.find(" skit ");
    while (pos != string::npos) {
        s.erase(pos, 5);
        pos = s.find(" skit ", pos);
    }

    pos = s.find(" click ");
    while (pos != string::npos) {
        s.erase(pos, 6);
        pos = s.find(" click ", pos);
    }

    pos = s.find(" klick ");
    while (pos != string::npos) {
        s.erase(pos, 6);
        pos = s.find(" klick ", pos);
    }

    pos = s.find(" clique ");
    while (pos != string::npos) {
        s.erase(pos, 7);
        pos = s.find(" clique ", pos);
    }

    pos = s.find(" by ");
    while (pos != string::npos) {
        s.erase(pos, 3);
        pos = s.find(" by ", pos);
    }

    pos = s.find(" the ");
    while (pos != string::npos) {
        s.erase(pos, 4);
        pos = s.find(" the ", pos);
    }

}


void removeLast4AndAllParentheses(string& s) 
{
    // Remove last 4 characters
    s.erase(s.size() - 4);

    // Remove all parentheses and everything in them
    size_t left = s.find('(');
    while (left != string::npos) {
        size_t right = s.find(')', left);
        if (right != string::npos) {
            s.erase(left, right - left + 1);
        }
        left = s.find('(', left + 1);
    }
    size_t l = s.find('[');
    while (l != string::npos) {
        size_t r = s.find(']', l);
        if (r != string::npos) {
            s.erase(l, r - l + 1);
        }
        l = s.find('(', l + 1);
    }
}

void removeFrontSpace(string& s)
{
    if (s.at(0) == ' ')
    {
        s.erase(0,1);
    }
}

void removeSubstring(string &str, const string &sub) {
    size_t pos = 0;
    while ((pos = str.find(sub, pos)) != string::npos) {
        str.erase(pos, sub.length());
    }
}

void removeEndSpace(string& s)
{
    if (s.at(s.size() - 1) == ' ')
    {
        s.pop_back();
    }
}

void sortAndRemoveDuplicates(vector<int>& v) {
    // sort the vector
    sort(v.begin(), v.end());

    // remove duplicates
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());
}

void replaceChar(std::string& str, char fromChar, char toChar) {
    for (char& c : str) {
        if (c == fromChar) {
            c = toChar;
        }
    }
}

int levenshtein(const std::string& s1, const std::string& s2) {
    int m = s1.size();
    int n = s2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    return dp[m][n];
}

int damerauLevenshtein(const string& s1, const string& s2) {
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


int updated_levenshtein (string longerstr, string shorterstr)
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







int main(int argc, char *argv[]) 
{
    string str2 = "kitten";
    string str1 = "kitten kitten";
    cout << updated_levenshtein(str1,str2) << endl;
    
    ifstream inFS;
    ofstream outcompareFS;
    ofstream outtestFS;
    string withArtist;
    inFS.open(argv[1]);
    outcompareFS.open(argv[2]);
    outtestFS.open(argv[3]);
    vector <string> oldPlaylist;
    vector <string> playlist;
    while (getline(inFS, withArtist))
    {
        
        oldPlaylist.push_back(withArtist);
        makeLowerCase(withArtist);
        removeLast4AndAllParentheses(withArtist);
        removeSpecialCharacters(withArtist);
        removeAnd(withArtist);
        string sub = "☠";
        removeSubstring(withArtist,sub);
        sub = "＂";
        removeSubstring(withArtist,sub);
        sub = "：";
        removeSubstring(withArtist,sub);
        sub = "⧸";
        removeSubstring(withArtist,sub);
        sub = "？";
        removeSubstring(withArtist,sub);
        replaceChar(withArtist, '-',' ');
        replaceChar(withArtist, '_',' ');
        removeExtraSpaces(withArtist);
        removeFrontSpace(withArtist);
        removeEndSpace(withArtist);
        playlist.push_back(withArtist);
        
        
    }  
    for(unsigned int i = 0;i < playlist.size();++i)
    {
        if (playlist.at(i).find(" - ") == string::npos)
        {
            outtestFS << playlist.at(i) << endl;
        }
    }
    
    for (unsigned int s = 0;s < 10;++s)
    {
        vector <int> temp;
        outcompareFS << s << " differences modified---------------------------------------------------------------------------" << endl;
        for (int i = 0; i < playlist.size(); i++) 
        {
            for (int j = i + 1; j < playlist.size(); j++) 
            {
                if (updated_levenshtein(playlist.at(i),playlist.at(j)) == s)
                {
                    outcompareFS << oldPlaylist.at(i) << endl;
                    outcompareFS << oldPlaylist.at(j) << endl << endl;
                    temp.push_back(i);
                    temp.push_back(j);
                }
            }
        }
        sortAndRemoveDuplicates(temp);
        for (unsigned int i = 0;i < temp.size();i++)
        {
            oldPlaylist.erase(oldPlaylist.begin() + temp.at(i));
            playlist.erase(playlist.begin() + temp.at(i));
            for (unsigned int j = i+1;j < temp.size();++j)
            {
                temp.at(j) -= 1;
            }
        }
    }
    vector <int> hello = {0,1,2,3,4,5,6,7};
    vector <int> temp = {0,3,5,7};
    for (unsigned int i = 0;i < temp.size();i++)
    {
        hello.erase(hello.begin() + temp.at(i));
        for (unsigned int j = i+1;j < temp.size();++j)
        {
            temp.at(j) -= 1;
        }
    }
    
    for (unsigned int s = 5;s < 15;++s)
    {
        outcompareFS << s << " differences original---------------------------------------------------------------------------" << endl;
        for (int i = 0; i < oldPlaylist.size(); i++) 
        {
            for (int j = i + 1; j < oldPlaylist.size(); j++) 
            {
                if (updated_levenshtein(oldPlaylist.at(i),oldPlaylist.at(j)) == s)
                {
                    outcompareFS << oldPlaylist.at(i) << endl;
                    outcompareFS << oldPlaylist.at(j) << endl << endl;
                }
            }
        }
    }
    
    
}

