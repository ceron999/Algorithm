/// <summary>
/// 저자 출제
/// 문자열 내 마음대로 정렬
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace P56
{
	int sortIdx;
	vector<string> solution(vector<string> strings, int n)
	{
		vector<string> answer;

		sortIdx = n;
		sort(strings.begin(), strings.end(), [](const string& a, const string& b)
			{
				if (a[sortIdx] != b[sortIdx])
					return a[sortIdx] < b[sortIdx];
				else
					return a < b;
			});
		answer = strings;
		return answer;
	}
}

//int main()
//{
//    vector<string> result2 = P56::solution({"sun", "bed", "car"}, 1);
//
//    for(string i : result2)
//        cout << i << " ";
//}