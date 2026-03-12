#include<iostream>
#include<vector>
#include<string>

using namespace std;

long long n, ret, a[100004], cnt[100004], s, e;

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    while (e < n)
    {
        if (cnt[a[e]] == 0)
        {
            cnt[a[e]]++;
            e++;
        }
        else
        {
            ret += e - s;
            cnt[a[s]]--;
            s++;
        }
    }

    ret += (e - s) * (e - s + 1) / 2;
    cout << ret;
}