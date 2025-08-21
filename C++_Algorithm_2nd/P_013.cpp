
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

namespace p13
{
    class Container
    {
        vector<vector<int>> lineContainer;

    public:
        Container(const vector<vector<int>>& board)
        {
            lineContainer.resize(board.size(), vector<int>(board[0].size(), 0));

            for (int i = 0;i < board[0].size();i++)
            {
                for (int j = 0;j < board.size();j++)
                {
                    lineContainer[i][j] = board[j][i];
                }
            }
        }

        int GetNumber(const int& line)
        {
            for (int i =0; i < lineContainer[line].size(); i++)
            {
                if (lineContainer[line][i] == 0)
                    continue;

                int getNum = lineContainer[line][i];
                lineContainer[line][i] = 0;
                return getNum;
            }

            return -1;
        }
    };
    int solution(vector<vector<int>> board, vector<int> moves) {
        int answer = 0;

        Container container(board);

        stack<int> pointCounter;
        for (int nowLine : moves)
        {
            int nowNum = container.GetNumber(nowLine - 1);
            if (nowNum == -1)
                continue;

            if (!pointCounter.empty() && pointCounter.top() == nowNum)
            {
                pointCounter.pop();

                answer += 2;
            }
            else
                pointCounter.push(nowNum);
        }
        return answer;
    }

}
//int main()
//{
//    vector<vector<int>>  input = 
//    { 
//        {0, 0, 0, 0, 0},
//        {0, 0, 1, 0, 3},
//        {0, 2, 5, 0, 1},
//        {4, 2, 4, 4, 2},
//        {3, 5, 1, 3, 1} 
//    };
//    auto input2 = { 1,5,3,5,1,2,1,4 };
//
//    int i = p13::solution(input,input2);
//
//        cout << i << endl;
//}