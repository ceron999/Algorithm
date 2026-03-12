#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;

	string s = to_string(a);
	s += to_string(b);
	cout << a + b - c << "\n";
	cout << stoi(s) - c;
}