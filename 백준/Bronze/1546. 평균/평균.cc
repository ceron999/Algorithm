#include <iostream>

using namespace std;

class list
{
public:
	list(int getCount)
		:subjectCount(getCount), maxScore(0), ave(0)
	{	
		scoreArr = new int[subjectCount];
		modifyScore = new float[subjectCount];
	}

	void GetScore()
	{
		for (int i = 0; i < subjectCount; i++)
		{
			cin >> scoreArr[i];
		}
	}

	void GetMaxScore()
	{
		maxScore = scoreArr[0];
		for (int i = 1; i < subjectCount; i++)
		{
			if (maxScore < scoreArr[i])
				maxScore = scoreArr[i];
		}
	}

	void ModifyScore()
	{
		for (int i = 0; i < subjectCount; i++)
		{
			modifyScore[i] = (float)scoreArr[i] / maxScore * 100;
		}
	}

	void PrintScore()
	{
		ave = 0;
		for (int i = 0; i < subjectCount; i++)
		{
			ave += modifyScore[i];
		}
		ave /= subjectCount;

		cout << ave;
	}

	~list()
	{
		delete[] scoreArr;
		delete[] modifyScore;
	}

private:
	int* scoreArr;
	int subjectCount;
	int maxScore;

	float* modifyScore;
	float ave;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int subjectCount;
	cin >> subjectCount;

	list list1(subjectCount);

	list1.GetScore();
	list1.GetMaxScore();
	list1.ModifyScore();
	list1.PrintScore();

	return 0;
}