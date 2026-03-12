#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int a, b, c;

vector<int> v;

int main()
{
	while(cin >> a >> b >> c)
	{ 
		if (a == 0 && b == 0 && c == 0) break;

		v.clear();
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		sort(v.begin(), v.end());

		if (v[0] * v[0] + v[1] * v[1] != v[2] * v[2])
			cout << "wrong\n";
		else
			cout << "right\n";
	}
}