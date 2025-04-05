/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/42892
/// 길찾기 게임
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
namespace P32
{
    class Node
    {
    public:
        vector<int> pos;
        Node* left;
        Node* right;

        Node(vector<int> getPos = { 0,0 }) : pos(getPos), left(nullptr), right(nullptr) {};
    };

    class BST
    {
    public:
        Node* root;
        vector<int> preorder;
        vector<int> postorder;

        BST(vector<int> getPos)
        {
            root = new Node(getPos);
        }

        void Insert(Node* curr, vector<int> input)
        {
            if (curr->pos[0] > input[0])
            {
                if (curr->left != nullptr)
                {
                    Insert(curr->left, input);
                }
                else
                {
                    curr->left = new Node(input);
                    return;
                }
            }
            else
            {
                if (curr->right != nullptr)
                {
                    Insert(curr->right, input);
                }
                else
                {
                    curr->right = new Node(input);
                    return;
                }
            }
        }

        void Preorder(Node* curr)
        {
            if (curr == nullptr)
                return;

            preorder.push_back(curr->pos[0]);
            Preorder(curr->left);
            Preorder(curr->right);
        }

        void Postorder(Node* curr)
        {
            if (curr == nullptr)
                return;

            Postorder(curr->left);
            Postorder(curr->right);
            postorder.push_back(curr->pos[0]);
        }

        ~BST()
        {

        }
    };

    vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
        vector<vector<int>> answer;
        unordered_map<int, int> idxMap;

        for (int i =0; i< nodeinfo.size(); i++)
        {
            idxMap[nodeinfo[i][0]] = i + 1;
        }

        // nodeinfo y가 큰 순서대로 나열 + x가 작은 순서대로 나열
        sort(nodeinfo.begin(), nodeinfo.end(), [](const vector<int>& a, const vector<int>& b)
            {
                if (a[1] == b[1])
                {
                    return a[0] < b[0];
                }
                return a[1] > b[1];

            });

        // 1. 정렬된 데이터를 bst에 추가
        BST bst(nodeinfo[0]);
        for (int i = 1;i < nodeinfo.size(); i++)
        {
            bst.Insert(bst.root, nodeinfo[i]);
        }
        bst.Preorder(bst.root);
        bst.Postorder(bst.root);

        vector<int> preorder;
        vector<int> postorder;

        for (int i = 0; i < nodeinfo.size(); i++)
        {
            // bst.preorder는 xpos 기준이므로 idxMap에서 idx로 변환
            preorder.push_back(idxMap[bst.preorder[i]]);
            postorder.push_back(idxMap[bst.postorder[i]]);
        }
        answer.push_back(preorder);
        answer.push_back(postorder);

        return answer;
    }
}

int main()
{
    vector<vector<int>> input = { {5,3}, {11,5}, {13,3}, {3,5}, {6,1},
                                  {1,3}, {8,6},  {7,2},  {2,2} };
    vector<vector<int>> result = P32::solution(input);

    for(vector<int> innerVec: result)
    {
        for(int i : innerVec)
            cout << i << " ";
        cout << endl;
    }
}