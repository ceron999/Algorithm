#include <iostream>
#include <vector>

using namespace std;

class list
{
public:
	list()
	{
		cin >> climb;
		cin >> slip;
		cin >> height;
		day = 1;
	}

	void GetDay()
	{
		int currHeight = 0;
		int maxHeight = height - climb;

		//낮에 기어가면 도착할 수 있는 날 하루 전의 날짜와 높이 세팅
		day = maxHeight / (climb - slip);
		currHeight = (climb - slip) * day;

		while (1)
		{
			day++;
			currHeight += climb;
			if (currHeight >= height) break;
			currHeight -= slip;
		}

		cout << day;
	}


	~list()
	{

	}

private:
	int day;
	int climb;
	int slip;
	int height;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.GetDay();

	return 0;
}