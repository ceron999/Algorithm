#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<long long> v;
long long n, ret = 1;

int main() 
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp; v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (auto i : v)
    {
        if (ret >= i)
            ret = i + 1;
        else
            break;
    }

    cout << ret;
}