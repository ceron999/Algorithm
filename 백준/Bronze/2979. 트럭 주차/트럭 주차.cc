#include<iostream>
#include<vector>

using namespace std;

// 목적 : 주차 비용 정산
// 1줄 -> A, B, C 주차비용
// 2~4줄 -> 트럭이 있던 시간
// 0 1 2 3 4 5 6 7 8
//   1 1 1 1 1  
//       1 1 
//     1 1 1 1 1 1  
// 0 5 6 3 3 5 5 5 0

vector<int> price;
vector<int> duration;

int main()
{
	price.resize(3, 0);
	duration.resize(101, 0);

	for (int i = 0; i < 3; i++)
		cin >> price[i];

	int in, out;
	for (int i = 0; i < 3; i++)
	{
		cin >> in >> out;

		for (int t = in; t < out; t++)
		{
			duration[t]++;
		}
	}

	int result = 0;
	for (int i = 0; i < duration.size(); i++)
	{
		int carCount = duration[i];
		
		switch (carCount)
		{
		case 0:
			break;
		case 1:
			result += price[0];
			break;
		case 2:
			result += price[1] * 2;
			break;
		case 3:
			result += price[2] * 3;
			break;
		}
	}

	cout << result;
	return 0;
}