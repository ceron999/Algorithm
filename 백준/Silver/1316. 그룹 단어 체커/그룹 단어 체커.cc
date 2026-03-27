#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
public:
	list()
	{
		cin >> testCase;
		wordCount = 0;

		strArr = new string[testCase];

		for (int i = 0; i < testCase; i++)
		{
			cin >> strArr[i];
		}

		isUsed = new bool[26];
		for (int i = 0; i < 26; i++)
		{
			isUsed[i] = false;
		}
	}

	//다음 글자가 이전 글자와 동일하면 true를 반환하는 함수입니다.
	bool IsRepetition(int getTestIdx,int getStrIdx)
	{
		if (strArr[getTestIdx][getStrIdx] == strArr[getTestIdx][getStrIdx + 1])
			return true;
		else
			return false;
	}

	int ChangeIdx(int getTestIdx, int getIdx)
	{
		int returnIdx = getIdx;

		for (; returnIdx < strArr[getTestIdx].size(); returnIdx++)
		{
			if (strArr[getTestIdx][getIdx] != strArr[getTestIdx][returnIdx])
				break;
		}
		return returnIdx - 1;
	}

	bool StrIsUsed(int getTestIdx, int getIdx)
	{
		int boolIdx = (int)strArr[getTestIdx][getIdx] - 97;

		if (!isUsed[boolIdx])
		{
			isUsed[boolIdx] = true;
			return false;
		}

		else
			return true;
	}

	void ReadWord()
	{
		int idx;
		
		//입력받은 테스트 케이스만큼 반복
		for (int testIdx = 0; testIdx < testCase; testIdx++)
		{
			//해당하는 문자열을 처음부터 끝까지 읽음
			for (int strIdx = 0; strIdx < strArr[testIdx].size(); strIdx++)
			{
				//다음 문자가 현재 문자랑 동일하면 다른 문자가 나오는 인덱스까지 이동
				if (IsRepetition(testIdx,strIdx))
				{
					if (StrIsUsed(testIdx, strIdx))
						break;

					idx = ChangeIdx(testIdx, strIdx);
					strIdx = idx;
				}
				else
				{
					if (StrIsUsed(testIdx, strIdx))
						break;
				}

				if (strIdx == strArr[testIdx].size() - 1)
					wordCount++;
			}

			//사용한 bool 값 초기화
			for (int i = 0; i < 26; i++)
			{
				isUsed[i] = false;
			}
		}

		cout << wordCount;
	}

	~list()
	{
		delete[] strArr;
		delete[] isUsed;
	}

private:
	int testCase;
	int wordCount;
	string* strArr;
	bool* isUsed;
};

//Main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list list1;
	list1.ReadWord();

	return 0;
}