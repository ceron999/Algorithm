#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <cstring>

using namespace std;

int sum, N;
int board[24][24];

void rotate(int board[24][24]) 
{
    int temp[24][24] = { 0 };
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            temp[i][j] = board[N - 1 - j][i];
        }
    }
    memcpy(board, temp, sizeof(temp));
}

void slide(int board[24][24]) 
{
    int temp[24][24];

    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0) continue;

            if (temp[i][cnt] == 0)
            {
                temp[i][cnt] = board[i][j];
            }
            else if (temp[i][cnt] == board[i][j])
            {
                temp[i][cnt] *= 2;
                cnt++;
            }
            else
            {
                cnt++;
                temp[i][cnt] = board[i][j];
            }
        }
    }
    memcpy(board, temp, sizeof(temp));
}


void counting(int board[24][24])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum = max(sum, board[i][j]);
        }
    }
}

void go(int here, int board[24][24]) {
    if (here == 5)
    {
        counting(board);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int cpy[24][24];
        memcpy(cpy, board, sizeof(cpy));
        slide(cpy);
        go(here + 1, cpy);
        rotate(board);
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    go(0, board);

    cout << sum;
    return 0;
}