#include <iostream>

using namespace std;

class list
{
public:
	list()
	{
		students = 0;
		scoreArr = 0;
		sum = 0.0f;
		ave = 0.0f;
		overAve = 0.0f;
	}

	void GetStudentsInfo()
	{
		cin >> students;

		scoreArr = new int[students];

		for (int i = 0; i < students; i++)
		{
			cin >> scoreArr[i];
			sum += scoreArr[i];
		}

		ave = sum / (float)students;

		for (int i = 0; i < students; i++)
		{
			if (scoreArr[i] > ave)
				overAve++;
		}
	}

	void PrintoverAve()
	{
		cout.precision(5);
		cout << (float)overAve / (float)students * 100 << "%\n";
	}

	~list()
	{
		delete[] scoreArr;
	}

private:
	int students;	//학생 수
	int* scoreArr;	//학생들의 점수 배열
	float sum;		//현재 반 학생들의 점수 총점
	float ave;		//반 평균
	int overAve;		//반 평균을 넘는 학생의 수
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.setf(ios::showpoint);

	int testCase;
	cin >> testCase;

	list* listArr = new list[testCase];

	for (int i = 0; i < testCase; i++)
	{
		listArr[i].GetStudentsInfo();
	}

	for (int i = 0; i < testCase; i++)
	{
		listArr[i].PrintoverAve();
	}

	return 0;
}