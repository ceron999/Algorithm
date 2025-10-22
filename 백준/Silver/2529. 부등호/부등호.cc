#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool visited[10];
int k;
vector<char> op;
vector<string> nums;

void dfs(vector<int> &v)
{
	if (v.size() == k + 1)
	{
		string ret;
		for (int i = 0;i < k + 1;i++)
		{
			ret.push_back(v[i] + '0');
		}
		nums.push_back(ret);
		return;
	}


	for (int next = 0; next <= 9;next++)
	{
		if (visited[next]) continue;

		int now = v.size();
		if (now != 0)
		{
			if (op[now - 1] == '<')
			{
				if (v[now - 1] >= next) continue;
			}
			else
			{
				if (v[now - 1] <= next) continue;
			}
		}

		v.push_back(next);
		visited[next] = true;

		dfs(v);

		v.pop_back();
		visited[next] = false;
	}
}

int main()
{
	cin >> k;
	for (int i = 0;i < k;i++)
	{
		char c;
		cin >> c;
		op.push_back(c);
	}

	vector<int> v;
	dfs(v);

	sort(nums.begin(), nums.end());
	cout << nums[nums.size() - 1] << "\n";
	cout << nums[0] << "\n";
}