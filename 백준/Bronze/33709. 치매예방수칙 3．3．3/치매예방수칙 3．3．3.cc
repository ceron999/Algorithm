#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string s;
int n;
vector<vector<char>> v(1004);
long long ret;


bool isSplit(const char& c)
{
    if (c == '|' || c == ':' || c == '#' || c == '.') return true;
    return false;
}

int main() 
{
    cin >> n;
    cin >> s;

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (isSplit(s[i]))
        {
            idx++;
            continue;
        }

        v[idx].push_back(s[i]);
    }

    for (int i = 0; i < 1004; i++)
    {
        long long temp = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            temp += v[i][j] - '0';

            if (j == v[i].size() - 1) break;
            temp *= 10;
        }

        ret += temp;
    }

    cout << ret;
}