#include<iostream>

using namespace std;



int main() 
{
    int n, k;
    cin >> n >> k;

    int ret = 0;
    if (n > 60 + k)
    {
        ret += (60 + k) * 1500;
        ret += (n - 60 - k) * 3000;
    }
    else
        ret += n * 1500;
    cout << ret;
}