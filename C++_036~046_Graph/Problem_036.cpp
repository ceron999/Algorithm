/// <summary>
/// 저자 출제
/// 깊이 우선 탐색 순회
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

        // 그래프에 새 노드 삽입
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
            // 방문한 노드 패스
            if (curr->isVisit)
                return;

            curr->isVisit = true;
            result.push_back(curr->value);

            // 자식이 없어도 패스
            if (curr->childs.size() == 0)
                return;

            // 자식 있으면 순회
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
        // 현재 node를 방문한 목록 및 방문한 경로 추가
        visited.insert(node);
        result.push_back(node);

        // 현재 node와 인접한 노드 중, 방문하지 않은 node들에 대해 깊이우선탐색을 계속 진행
        for (char neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor);
            }
        }
    }

    vector<char> solution(vector<pair<char, char>> graph, char start) {
        // 인접 리스트 생성
        for (auto& edge : graph) {
            char u = edge.first;
            char v = edge.second;
            adjList[u].push_back(v);
        }

        // 시작 노드부터 깊이우선탐색 시작
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