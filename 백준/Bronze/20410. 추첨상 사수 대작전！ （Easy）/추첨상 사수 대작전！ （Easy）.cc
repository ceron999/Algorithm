#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int m, seed, x1, x2, a, c;

int main() 
{
    cin >> m >> seed >> x1 >> x2;

    for (int a = 0; a < m; a++) {
        int c = (x1 - a * seed) % m;

        if (c < 0)
            c += m;

        if ((a * x1 + c) % m == x2) {
            cout << a << " " << c;
            return 0;
        }
    }
}