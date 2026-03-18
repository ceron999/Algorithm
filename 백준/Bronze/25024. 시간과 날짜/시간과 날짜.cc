#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int T;
int x, y;

bool go_x(int x, int y)
{
    if (x >= 0 && x < 24)
    {
        if (y >= 0 && y < 60)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool go_y(int x, int y)
{
    if (x== 0 || x > 12) return false;

    if (x == 2)
    {
        if (y > 0 && y <= 29) return true;
        else return false;
    }
    else if (x == 4 || x == 6 || x == 9 || x == 11)
    {
        if (y > 0 && y <= 30) return true;
        else return false;
    }
    else
    {
        if (y > 0 && y <= 31) return true;
        else return false;
    }
}

int main() 
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> x >> y;

        if (go_x(x, y))
            cout << "Yes ";
        else
            cout << "No ";

        if (go_y(x, y))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}