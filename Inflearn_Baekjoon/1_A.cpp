#include<iostream>
#include<vector>

using namespace std;

int n, m, map[9][9], maxSize = 0;
int test[9][9];

// 1. 1을 3개를 둔다.
// 2. dfs를 통해 2를 퍼트린다.
// 3. 0 개수를 확인한다.

void spread()
{

}

void installWall(int y, int x, int size)
{
	if (size == 3)
	{
		for (int i = 0; i < n;i++)
			for (int j = 0;j < m;j++)
			{
				test[i][j] = map[i][j];
			}

		spread();
		return;
	}

	for(int i= y + 1; i< n;i++)
		for (int j = x + 1;j < m;j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				installWall(i, j, size + 1);
				map[i][j] = 0;
			}
		}
}
int main()
{
	cin >> n >> m;
	
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> map[i][j];
	
	installWall(-1,-1, 0);
	
	//
	cout << endl;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
			cout << test[i][j] << " ";
		cout << endl;
	}
}