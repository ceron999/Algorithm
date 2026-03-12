#include<iostream>

using namespace std;



int main() 
{
    int t, ret = 0;
    int temp;
    cin >> t;
    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        if (temp == t) ret++;
    }
    cout << ret;
}