#include <iostream>
#include <vector>

using namespace std;

class list
{
public:
	list()
	{
		cin >> height;
		cin >> width;
		cin >> num;
		roomNum = 0;
	}

	void GetRoomNum()
	{
		int room_h = 0;
		int room_w = 0;

		room_h = num % height;
		if (room_h == 0) room_h = height;

		if (num % height != 0)
			room_w = num / height + 1;
		else
			room_w = num / height;

		roomNum = 100 * room_h + room_w;

		cout << roomNum << "\n";
	}

	~list()
	{

	}

private:
	int height;
	int width;
	int num;
	int roomNum;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	list* listArr = new list[testCase];

	for (int i = 0; i < testCase; i++)
		listArr[i].GetRoomNum();

	delete[] listArr;
	return 0;
}