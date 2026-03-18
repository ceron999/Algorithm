#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

long long X1, X2, Y1, Y2, R1, R2;

int main() 
{
    cin >> X1 >> Y1 >> R1;
    cin >> X2 >> Y2 >> R2;

    long long xDist = abs(X1 - X2);
    long long yDist = abs(Y1 - Y2);

    if (xDist * xDist + yDist * yDist < (R1 + R2) * (R1 + R2))
        cout << "YES";
    else
        cout << "NO";
}