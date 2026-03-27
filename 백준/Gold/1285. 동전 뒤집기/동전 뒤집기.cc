#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

char board[21][21];
char test[21][21];
int n, minT = 9999;

void changeCol(int idx)
{
	for (int i = 0; i < n; i++)
	{
		if (test[i][idx] == 'H') 
			test[i][idx] = 'T';
		else test[i][idx] = 'H';
	}
}
void changeRow(int idx)
{
	for (int i = 0; i < n; i++)
	{
		if (test[idx][i] == 'H')
			test[idx][i] = 'T';
		else test[idx][i] = 'H';
	}
}

int getColTCount(int col)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (test[i][col] == 'T')
			cnt++;
	}

	return cnt;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < n; j++)
		{
			board[i][j] = s[j];
		}
	}

	for (int rowLayer = 0; rowLayer < (1 << n); rowLayer++)
	{
		memcpy(&test, &board, sizeof(board));
		for (int idx = 0; idx < n; idx++)
		{
			if (rowLayer & (1 << idx))
			{
				changeRow(idx);
			}
		}

		int curr = 0;
		for (int idx = 0; idx < n; idx++)
		{
			int colTCount = getColTCount(idx);
			curr += min(colTCount, n - colTCount);
		}

		minT = min(minT, curr);
	}

	cout << minT;
}