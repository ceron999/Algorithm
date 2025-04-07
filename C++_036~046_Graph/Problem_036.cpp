/// <summary>
/// ���� ����
/// ���� �켱 Ž�� ��ȸ
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
namespace P33
{
    class node
    {
    public:
        bool isVisit;
        char value;
        vector<node*> childs;

        node(char input = 'Z')
        {
            isVisit = false;
            value = input;
        }
    };

    class Graph
    {
    public:
        node* start;

        Graph(const pair<char, char> &input)
        {
            start = new node(input.first);
            start->childs.push_back(new node(input.second));
        }

        // �׷����� �� ��� ����
        void Insert(node* &curr, const pair<char, char>& input)
        {
            if (curr->value == input.first)
            {
                node* childNode = FInd(start, input.second);
                if (childNode == nullptr)
                    curr->childs.push_back(new node(input.second));
                else
                    curr->childs.push_back(childNode);
            }

            else
            {
                if (curr->childs.size() == 0)
                    return;
                for (node* nowNode : curr->childs)
                {
                    Insert(nowNode, input);
                }
            }
        }
        node* FInd(node* &curr, const char input)
        {
            if (curr == nullptr) return nullptr;

            if (curr->value == input)
            {
                return curr;
            }

            else
            {
                for (node* nowNode : curr->childs)
                {
                    node* result = FInd(nowNode, input);
                    if (result != nullptr)
                        return result;
                }
            }
            return nullptr;
        }

        void Traversal(node* &curr, vector<char> &result)
        {
            // �湮�� ��� �н�
            if (curr->isVisit)
                return;

            curr->isVisit = true;
            result.push_back(curr->value);

            // �ڽ��� ��� �н�
            if (curr->childs.size() == 0)
                return;

            // �ڽ� ������ ��ȸ
            for (node* childNode : curr->childs)
            {
                if (childNode->isVisit)
                    return;
                else
                {
                    Traversal(childNode, result);
                }
            }
        }
    };

    vector<char> solution(vector<pair<char, char>> graph, char start)
    {
        vector<char> answer;

        Graph graphTree(graph[0]);
        for (int i = 1; i < graph.size(); i++)
        {
            graphTree.Insert(graphTree.start, graph[i]);
        }

        graphTree.Traversal(graphTree.start, answer);
        return answer;
    }
}

namespace P33_Answer
{
    unordered_map<char, vector<char>> adjList;
    vector<char> result;
    unordered_set<char> visited;

    void dfs(char node) {
        // ���� node�� �湮�� ��� �� �湮�� ��� �߰�
        visited.insert(node);
        result.push_back(node);

        // ���� node�� ������ ��� ��, �湮���� ���� node�鿡 ���� ���̿켱Ž���� ��� ����
        for (char neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor);
            }
        }
    }

    vector<char> solution(vector<pair<char, char>> graph, char start) {
        // ���� ����Ʈ ����
        for (auto& edge : graph) {
            char u = edge.first;
            char v = edge.second;
            adjList[u].push_back(v);
        }

        // ���� ������ ���̿켱Ž�� ����
        dfs(start);
        return result;
    }
}
//int main()
//{
//    vector<char> result2 = P33::solution
//        ({{'A','B'},{'A','C'}, {'B','D'}, {'B','E'}, {'C','F'}, {'E','F'}}, 'A');
//
//    for(char i : result2)
//        cout << i << " ";
//}