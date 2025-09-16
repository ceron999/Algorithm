#include<iostream>
#include<vector>

using namespace std;

int dy[] = { -1, 0, 1,0 };
int dx[] = { 0, 1, 0,-1 };

int n, a[51][51], l, r;
bool visited[51][51];
vector<pair<int,int>> unions;
int unionSum = 0, timeCnt = 0;
bool flag = false;

// 1. 인접한 나라의 인구차이가 L < < R이라면 오쁜
// 2. 모두 오쁜하면 이동 시작
// 3. 국경선이 열려있어 이동할 수 있으면 '연합'
// 4. 연합의 각 칸 인구수는 (연합의 인구수 / 연합을 이루고 있는 칸의 개수)
// 5. 1 ~4를 반복

void dfs(int y, int x)
{
	visited[y][x] = true;
	unions.push_back({ y, x });
	unionSum += a[y][x];

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
		if (visited[ny][nx]) continue;

		int diff = abs(a[y][x] - a[ny][nx]);
		
		if (diff >= l && diff <= r)
		{
			flag = true;
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	while (true)
	{
		flag = false;
		fill(&visited[0][0], &visited[0][0] + 51 * 51, false);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j]) continue;
				
				unions.clear();
				dfs(i, j);

				int remain = unionSum / unions.size();
				for (auto it : unions)
				{
					a[it.first][it.second] = remain;
				}

				unionSum = 0;
			}
		}

		if (!flag)
			break;
		timeCnt++;
	}

	cout << timeCnt;
}