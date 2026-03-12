#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string s;

int main() 
{
    while (getline(cin, s))
    {
        if (s == "0") return 0;

        string temp = s;
        reverse(s.begin(), s.end());

        if (temp == s) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}