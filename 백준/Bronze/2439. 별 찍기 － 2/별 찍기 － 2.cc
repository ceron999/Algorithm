#include <iostream>

using namespace std;

class star
{
public:
	void GetInt()
	{
		cin >> testCase;
	}

	void PrintStar()
	{
		for (int i = testCase; i > 0; i--)
		{
			for (int j = 1; j < i; j++)
				cout << " ";
			for (int j = i; j <= testCase;j++)
				cout << "*";
			cout << "\n";
		}
	}
private:
	int testCase;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	star starClass;
	starClass.GetInt();
	starClass.PrintStar();

	return 0;
}