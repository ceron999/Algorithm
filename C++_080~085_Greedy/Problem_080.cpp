/// <summary>
/// 저자 출제
/// 거스름돈 주기
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P80
{
	int change[4] = { 100, 50, 10, 1 };

	vector<int> solution(int amount)
	{
		vector<int> answer;
		int amountIdx = 0;
		while (amount > 0)
		{
			if (amount >= change[amountIdx])
			{
				amount -= change[amountIdx];
				answer.push_back(change[amountIdx]);
			}
			else
				amountIdx++;
		}

		return answer;
	}
}

int main()
{
    vector<int> result = P80::solution(123);

    for (int i : result)
        cout << i << " ";
}