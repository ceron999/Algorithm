#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, m, ret;
vector<int> v;

void go(int here, vector<int> &curr)
{
    if (curr.size() == 3)
    {
        int sum = 0;
        for (int i : curr) sum += i;
        if (sum <= m && sum > ret) ret = sum;
        return;
    }
    if (here == v.size()) return;


    curr.push_back(v[here]);
    go(here + 1, curr);
    curr.pop_back();
    go(here + 1, curr);
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> result;
    go(0, result);

    cout << ret;
}