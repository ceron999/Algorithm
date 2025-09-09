#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void PrintV(vector<int>& v)
{
	for (int i = 0;i < v.size();i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v1 = { 1,2,3 };
	vector<int> result;

	for (int i = 0; i < v1.size(); i++) result.push_back(v1[i]);

	do
	{
		PrintV(result);

	} while (next_permutation(result.begin(), result.end()));


	return 0;
}