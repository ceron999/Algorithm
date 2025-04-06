/// <summary>
/// ���� ����
/// ������ ���Ͽ� ���ε� �˰��� ����
/// 
/// ���� find ��� ����
/// 1. parnet[x]�� ��Ʈ���� ����
/// parents[3] = 2
/// parents[2] = 1
/// parents[1] = 0
/// parents[0] = 0
/// �̸� 3 - 2 - 1 - 0���� ���
/// 2. parent[0] =0 -> parent[1] =0 -> ... -> parent[3] = 0���� ���������� ����
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
namespace P33
{
    void Union(char node1, char node2, unordered_map<int, int>& set)
    {
        int node1Value = node1 - '0';
        int node2Value = node2 - '0';
        int node1Root = set[node1Value];
        int node2Root = set[node2Value];
        int node1Rank = 0;
        int node2Rank = 0;

        if (node1Root == -1)
        {
            node1Root = node1Value;
            set[node1Value] = node1Value;
        }
        if (node2Root == -1)
        {
            node2Root = node2Value;
            set[node2Value] = node2Value;
        }
        // ��� 1 ��Ʈ�� ��ũ ���ϱ�
        while (node1Root != -1 && node1Root != set[node1Root])
        {
            node1Root = set[node1Root];
            node1Rank++;
        }
        // ��� 2 ��Ʈ�� ��ũ ���ϱ�
        while (node2Root != -1 && node2Root != set[node2Root])
        {
            node2Root = set[node2Root];
            node2Rank++;
        }
        // ��� 1 ��Ʈ == ��� 2 ��Ʈ�� ����
        if (node1Root == node2Root)
            return;
        // ��� 1 ��Ʈ != ��� 2 ��Ʈ�� ��ũ ��
        else
        {
            if (node1Rank >= node2Rank)
            {
                set[node2Value] = node1Value;
            }
            else
            {
                set[node1Value] = node2Value;
            }
        }

    }
    bool Find(char node1, char node2, unordered_map<int, int>& set)
    {
        int node1Value = node1 - '0';
        int node2Value = node2 - '0';
        int node1Root = set[node1Value];
        int node2Root = set[node2Value];

        if (node1Root == -1)
        {
            node1Root = node1Value;
            set[node1Value] = node1Value;
        }
        if (node2Root == -1)
        {
            node2Root = node2Value;
            set[node2Value] = node2Value;
        }
        // ��� 1 ��Ʈ�� ��ũ ���ϱ�
        while (node1Root != -1 && node1Root != set[node1Root])
        {
            node1Root = set[node1Root];
        }
        // ��� 2 ��Ʈ�� ��ũ ���ϱ�
        while (node2Root != -1 && node2Root != set[node2Root])
        {
            node2Root = set[node2Root];
        }

        return (node1Root == node2Root) ? true : false;
    }

    vector<bool> solution(int k, vector<vector<char>> operations)
    {
        vector<bool> answer;

        unordered_map<int, int> set(k);
        for (int i = 0; i < k; i++)
            set[i] = -1;

        for (vector<char> nowOp : operations)
        {
            if (nowOp[0] == 'u')
            {
                Union(nowOp[1], nowOp[2], set);
            }
            else if (nowOp[0] == 'f')
            {
                answer.push_back(Find(nowOp[1], nowOp[2], set));
            }
            else
                cout << "����!!!!!!!!!!!!!!!!" << endl;
        }

        return answer;
    }
}

namespace P33_Book
{
    vector<int> parents;
    vector<int> rankData;

    // ���ڸ� ���ڷ� ��ȯ
    int charToInt(char c) {
        return c - '0';
    }

    int find(int x) {
        // x�� �θ� �ڽ��� ��� ��Ʈ��带 ã�����Ƿ� ��ȯ    
        if (parents[x] == x) {
            return x;
        }

        // ���ε� ���� ��, ��ξ��� ���
        parents[x] = find(parents[x]);

        return parents[x];
    }

    void unionSet(int x, int y) {
        int root1 = find(x);
        int root2 = find(y);

        // ��Ʈ ��尡 ���� ��� ���Ͽ� ������ �� �ʿ䰡 ����
        if (root1 != root2) {
            // ��ũ��� �˰������� ���Ͽ� ���� ����  
            if (rankData[root1] < rankData[root2]) {
                parents[root1] = root2;
            }
            else if (rankData[root1] > rankData[root2]) {
                parents[root2] = root1;
            }
            else {
                parents[root2] = root1;
                rankData[root1]++;
            }
        }
    }

    vector<bool> solution(int k, vector<vector<char>> operations) {
        parents.resize(k);
        rankData.resize(k, 0);

        // �ʱ⿡ �� ���� �ڽ��� �θ�� ����
        for (int i = 0; i < k; ++i) {
            parents[i] = i;
        }

        vector<bool> results;
        for (const auto& op : operations) {
            if (op[0] == 'u') {
                int x = charToInt(op[1]);
                int y = charToInt(op[2]);
                unionSet(x, y);
            }
            else if (op[0] == 'f') {
                int x = charToInt(op[1]);
                int y = charToInt(op[2]);
                // ���ε� ������ ��ȭ x,y�� ��Ʈ��尡 ������ Ȯ���ؼ� ��� ����
                results.push_back(find(x) == find(y));
            }
        }

        return results;
    }
}

//int main()
//{
//    /*vector<bool> result = P33::solution(3, { {'u', '0', '1'},{'u', '1', '2'} ,{'f', '0', '2'} });
//
//    for (int i : result)
//        cout << i << " ";
//    cout << endl;*/
//    vector<bool> result2 = P33::solution(4, { {'u', '0', '1'},{'u', '2', '3'} ,{'f', '0', '1'} ,{'f', '0', '2'} });
//
//    for(int i : result2)
//        cout << i << " ";
//}