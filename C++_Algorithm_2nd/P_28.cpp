
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace p28
{
    class Node
    {
    public:
        int value;

        Node* left;
        Node* right;

        Node(int num)
        {
            value = num;
            left = nullptr;
            right = nullptr;
        }
    };
    class Tree
    {
        Node* root;

        Node* InsertNode(Node* node, int key)
        {
            if (!node)
                return new Node(key);

            if (key < node->value)
                node->left = InsertNode(node->left, key);
            else
                node->right = InsertNode(node->right, key);

            return node;
        }

        bool SearchKey(Node* node, int key)
        {
            if (!node)
                return false;

            if (key == node->value)
                return true;

            return key < node->value ? SearchKey(node->left, key) : SearchKey(node->right, key);
        }

    public:
        Tree() : root(nullptr) {}

        void Insert(int key)
        {
            root = InsertNode(root, key);
        }

        bool Search(int key)
        {
            return SearchKey(root, key);
        }
    };


    vector<int> solution(vector<int> node) {
        vector<int> answer;

        Tree tree;
        for(int i : node)
        {
            tree.Insert(i);
        }

        return answer;
    }

}
//
//int main()
//{
//    vector<int> input = { 1,2,3,4,5,6,7 };
//
//    vector<int> i = p28::solution(input);
//}