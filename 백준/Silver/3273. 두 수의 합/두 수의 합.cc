#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int a[100004], n, x, l, r, ret;

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    
    r = n - 1;

    sort(a, a + n);

    while (l < r)
    {
        if (a[l] + a[r] > x)
        {
            r--;
        }
        else if (a[l] + a[r] < x)
        {
            l++;
        }
        else
        {
            ret++; l++;
        }
    }

    cout << ret;
}