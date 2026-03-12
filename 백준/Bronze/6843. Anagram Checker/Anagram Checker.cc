#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string s1, s2;
vector<char> v1;
vector<char> v2;

int main() 
{
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != ' ') v1.push_back(s1[i]);
    }

    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] != ' ') v2.push_back(s2[i]);
    }

    if (v1.size() != v2.size())
    {
        cout << "Is not an anagram.";
        return 0;
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            cout << "Is not an anagram.";
            return 0;
        }
    }
    
    cout << "Is an anagram.";
    return 0;
}