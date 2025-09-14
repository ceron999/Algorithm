#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int h, w;
char map[101][101];
int result[101][101];

void updateCloud()
{

}

int main()
{
	cin >> h >> w;
	fill(&result[0][0], &result[0][0] + 101 * 101, -1);

	for (int i = 0; i < h;i++)
		for (int j = 0; j < w;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'c') result[i][j] = 0;
		}

	for (int i = 0; i < h;i++)
	{
		for (int j = 0; j < w;j++)
		{
			if (map[i][j] == 'c')
			{
				for (int k = j + 1; k < w;k++)
				{
					if (result[i][k] == -1)
						result[i][k] = result[i][k - 1] + 1;
				}
			}
		}
	}

	// 디버
	for (int i = 0; i < h;i++)
	{
		for (int j = 0; j < w;j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}