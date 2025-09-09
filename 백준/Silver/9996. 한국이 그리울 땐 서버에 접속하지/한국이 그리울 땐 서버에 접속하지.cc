#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define YES "DA"
#define NO "NE"

// N : 총 파일 개수
// pattern : 패턴

int n;
string pattern;
vector<string> patternSplit;
vector<string> files;

vector<string> split(const string& input, string delimiter)
{
	vector<string> result;

	auto start = 0;
	auto end = input.find(delimiter);

	while (end != string::npos)
	{
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}

	result.push_back(input.substr(start));
	return result;
}

bool IsContainPattern(string& input)
{
	string front = patternSplit[0];
	string back = patternSplit[1];

	size_t frontSize = front.size();
	size_t backSize = back.size();

	if (input.size() < frontSize + backSize)
		return false;

	if (input.compare(0, frontSize, front) != 0) 
		return false;
	if (input.compare(input.size() - backSize, backSize, back) != 0) 
		return false;

	return true;
}

int main()
{
	cin >> n;
	cin >> pattern;
	patternSplit = split(pattern, "*");

	files.resize(n, "");

	for (int i = 0;i < n;i++)
		cin >> files[i];

	for (string file : files)
	{
		cout << (IsContainPattern(file) ? YES : NO) << "\n";
	}
	return 0;
}