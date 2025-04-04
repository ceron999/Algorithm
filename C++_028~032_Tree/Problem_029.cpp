/// <summary>
/// 저자 출제
/// 이진 탐색 트리 구현
/// </summary>

#include <iostream>
#include<vector>
#include <string>

using namespace std;
namespace P29
{
    class node
    {
    public:
        int value;
        node* left;
        node* right;

        node(int getValue = 0) : value(getValue), left(nullptr), right(nullptr){}
    };

    class tree
    {
    public:
        node* root;
        tree(int value)
        {
            root = new node(value);
        }

        void Insert(node* &curr, const int &value)
        {
            if (value < curr->value)
            {
                if (curr->left == nullptr)
                    curr->left = new node(value);
                else
                    Insert(curr->left, value);
            }
            else
            {
                if (curr->right == nullptr)
                    curr->right = new node(value);
                else
                    Insert(curr->right, value);
            }
        }

        node* Insert2(node*& curr, const int& value)
        {
            if (!curr)
                return new node(value);

            if (value < curr->value)
            {
                curr->left = Insert2(curr->left, value);
            }
            else
            {
                curr->right = Insert2(curr->right, value);
            }
        }

        bool Find(node*& curr, int value)
        {
            if (curr == nullptr) return false;

            if (value == curr->value) return true;

            else if (value > curr->value)
            {
                return Find(curr->right, value);
            }

            else
            {
                return Find(curr->left, value);
            }
        }

        ~tree() {}
    };
    vector<bool> solution(vector<int> lst, vector<int> search_lst)
    {
        vector<bool> answer;

        tree nowTree(lst[0]);

        // 1. lst의 이진 탐색 트리를 구현
        for (auto it = lst.begin() + 1; it != lst.end(); ++it)
        {
            nowTree.Insert2(nowTree.root, *it);
        }

        // 2. search_lst의 원소가 lst에 있는지 확인 후 반환
        for (int nowSearchNum : search_lst)
        {
            bool result = nowTree.Find(nowTree.root, nowSearchNum);
            answer.push_back(result);
        }
        return answer;
    }
}

//int main()
//{
//    vector<bool>  result = P29::solution({ 1,3,5,7,9 }, {2,4,6,8,10});
//
//    for(bool bools : result)
//        cout << bools << " ";
//}