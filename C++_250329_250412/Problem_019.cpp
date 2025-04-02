/// <summary>
/// 저자 문제
/// 문자열 해싱을 이용한 검색 함수 만들기
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_set>

using namespace std;
namespace P19
{
	long long Hash(const string &s)
	{
		long long result = 0;
		const int p = 31;
		const long long m = 1000000007;

		for (int i =0; i< s.size(); i++)
		{
			long long nowChar = (long long)s[i];;
			for (int pCount = 0; pCount < i; pCount++)
			{
				nowChar *= p;
			}
			result += nowChar;
		}
		result %= m;
		return result;
	}

	vector<bool> solution(vector<string> string_list, vector<string> query_list)
	{
		vector<bool> answer;
		map<long long, string> hashTable;

		for (string s : string_list)
		{
			long long hashIdx = Hash(s);
			hashTable.insert({ hashIdx, s });
			cout << hashIdx << " " << s << endl;
		}

		for (string searchString : query_list)
		{
			long long hashIdx = Hash(searchString);
			auto it = hashTable.find(hashIdx);
			if (it != hashTable.end())
			{
				answer.push_back(true);
			}
			else
			{
				answer.push_back(false);
			}
		}
		return answer;
	}

	vector<bool> solution2(vector<string> string_list, vector<string> query_list)
	{
		vector<bool> answer;
		unordered_set<long long> hashTable;

		for (string s : string_list)
		{
			long long hashIdx = Hash(s);
			hashTable.insert({ hashIdx });
			cout << hashIdx << " " << s << endl;
		}

		for (string searchString : query_list)
		{
			long long hashIdx = Hash(searchString);
			bool found = (hashTable.find(hashIdx) != hashTable.end() );
			if (found)
			{
				answer.push_back(true);
			}
			else
			{
				answer.push_back(false);
			}
		}
		return answer;
	}
}

//int main()
//{
//	vector<bool> result = P19::solution2({ "apple", "banana", "cherry" }, { "banana", "kiwi", "melon", "apple"});
//	for (int i : result)
//		cout << i << " ";
//}