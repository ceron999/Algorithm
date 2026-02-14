#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

const int INF = 987654321;

int maxMp;
int maxMf;
int maxMs;
int maxMv;

int n, minSum = INF, nowSum = 0;

int a[20][5];

vector<int> minPick;
vector<int> nowPick;

bool check(int layer)
{
	nowPick.clear();
	nowSum = 0;

	int mp = 0;
	int mf = 0;
	int ms = 0;
	int mv = 0;

	for (int i = 1; i <= n;i++)
	{
		if (layer & (1 << (i - 1)))
		{
			nowPick.push_back(i);

			mp += a[i][0];
			mf += a[i][1];
			ms += a[i][2];
			mv += a[i][3];

			nowSum += a[i][4];
		}
	}

	if (mp >= maxMp && mf >= maxMf && ms >= maxMs && mv >= maxMv)
	{
		
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> maxMp >> maxMf >> maxMs >> maxMv;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	}

	for (int layer = 1; layer < (1 << n); layer++)
	{
		if (check(layer))
		{
			if (minSum > nowSum || (nowSum == minSum && nowPick < minPick))
			{
				minSum = nowSum;
				minPick = nowPick;
			}
		}
	}

	if (minSum == INF)
	{
		cout << -1;
		return 0;
	}

	cout << minSum << "\n";
	for (auto i : minPick)
	{
		cout << i << " ";
	}
}