/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42861
/// 섬 연결하기
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace P35
{
    vector<int> parent;     // 각 노드의 연결을 확인
    vector<int> setRank;
    int cost;

    int Find(int x)
    {
        if (parent[x] == x)
            return x;

        parent[x] = Find(parent[x]);

        return parent[x];
    }

    bool IsAllConnect()
    {
        int start = parent[0];
        for (int node : parent)
        {
            if (start != Find(node))
                return false;
        }
        return true;
    }

    void UnionSet(vector<int> inputCost)
    {
        int root1 = Find(inputCost[0]);
        int root2 = Find(inputCost[1]);

        if (root1 != root2)
        {
            if (setRank[root1] < setRank[root2])
            {
                parent[root1] = root2;
                cost += inputCost[2];
            }
            else if (setRank[root1] > setRank[root2])
            {
                parent[root2] = root1;
                cost += inputCost[2];
            }
            else
            {
                parent[root2] = root1;
                setRank[root1]++;
                cost += inputCost[2];
            }
        }
    }

    int solution(int n, vector<vector<int>> costs) 
    {
        int answer = 0;
        // cost가 값싼 순으로 나열
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b)
            {
                if (a[2] != b[2])
                    return a[2] < b[2];
                else if (a[0] != b[0])
                    return a[0] < b[0];
                else
                    return a[1] < b[1];
            });

        // parent 초기화
        parent.resize(n);
        setRank.resize(n, 0);
        cost = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

        for (vector<int> nowCost : costs)
        {
            if (!IsAllConnect())
                UnionSet(nowCost);
            else
                break;
        }

        answer = cost;
        return answer;
    }
}

int main()
{
    int result = P35::solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1 }, { 2,3,8 } });

        cout << result << " ";
}