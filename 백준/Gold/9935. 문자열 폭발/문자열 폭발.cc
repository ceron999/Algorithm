#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

string S, T, ret;

int main()
{
	cin >> S >> T;

	for (char a : S)
	{
		ret += a;
		if (ret.size() >= T.size() && ret.substr(ret.size() - T.size(), T.size()) == T)
		{
			ret.erase(ret.end() - T.size(), ret.end());
		}
	}

	if (!ret.size()) cout << "FRULA";
	else cout << ret << "\n";
	
}