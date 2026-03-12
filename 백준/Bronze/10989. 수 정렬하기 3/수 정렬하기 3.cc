#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int n;
int a[1000004];

int main() 
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        a[temp]++;
    }

    for (int i = 0; i < 1000001; i++)
    {
        if (a[i] == 0) continue;
        for (int j = 0; j < a[i]; j++)
        {
            cout << i << "\n";
        }
    }
}