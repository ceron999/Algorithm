/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/87946
/// �Ƿε�
/// </summary>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace P49
{
    vector<vector<int>> resultDungeons;
    vector<vector<int>> currDungeons;

    void backTrack(int nowK, vector<vector<int>> remainDungeons)
    {
        // 1. �����ִ� ������ ������ ��ȯ
        if (remainDungeons.size() == 0) 
        {
            if (currDungeons.size() > resultDungeons.size())
                resultDungeons = currDungeons;
            return;
        }

        // 2. ���� ������ �� ���Ƶ� �ִ� ������ �ȵǸ� �ߴ�
        if (currDungeons.size() + remainDungeons.size() < resultDungeons.size()) return;

        // 3. ��Ʈ��ŷ
        for (int i =0; i< remainDungeons.size(); i++)
        {
            vector<vector<int>> newRemain = remainDungeons;

            // ���� ������ �ش� ���� ����
            if (remainDungeons.size() > 0 && nowK < remainDungeons[i][0])
            {
                newRemain.erase(newRemain.begin() + i);
                backTrack(nowK, newRemain);
                return;
            }

            currDungeons.push_back(remainDungeons[i]);

            // ���� ���� ������Ʈ
            newRemain.erase(newRemain.begin() + i);

            backTrack(nowK - remainDungeons[i][1], newRemain);
            currDungeons.pop_back();
        }

    }

    int solution(int k, vector<vector<int>> dungeons) 
    {
        int answer = -1;

        backTrack(k, dungeons);
        answer = (resultDungeons.size() != 0) ? resultDungeons.size() : -1;
        return answer;
    }
}

namespace P49_Answer
{
    int maxDepth = 0;
    bool visited[8] = { false, };

    // �ִ�湮 �������� �����ϸ鼭 ���̿켱Ž������ ������ Ž��
    void exploreDungeon(int depth, int power, vector<vector<int>>& dungeons) {
        if (maxDepth < depth)
            maxDepth = depth;

        for (int i = 0; i < dungeons.size(); i++) {
            // �̹� �湮�� �����̰ų�,  �ּ� �ʿ� �Ƿε��� ���� ���� �Ƿε� ���� ���� ��� 
            if (visited[i] || dungeons[i][0] > power)
                continue;

            // �湮�� ������ ������ ��� ��츦 Ȯ��
            visited[i] = true;
            exploreDungeon(depth + 1, power - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }

    int solution(int initialPower, vector<vector<int>> dungeons) {
        // ����Ž�� ����
        exploreDungeon(0, initialPower, dungeons);

        return maxDepth;
    }
}
//int main()
//{
//    int result2 = P49::solution(79, { { 80,20},{ 50,40 }, { 30,10 } });
//
//        std::cout << result2 << " ";
//}