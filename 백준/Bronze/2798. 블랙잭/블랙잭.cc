#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, m, ret;
vector<int> v;

void go(int here, int cnt, int sum)
{
    if (sum > m) return;
    
    if (cnt == 3)
    {
        ret = max(ret, sum);
        return;
    }

    if (here == n) return;

    go(here + 1, cnt + 1, sum + v[here]);
    go(here + 1, cnt, sum);
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
    go(0, 0, 0);

    cout << ret;
}