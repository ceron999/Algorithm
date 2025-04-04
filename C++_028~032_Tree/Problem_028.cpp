/// <summary>
/// ���� ����
/// �迭�� Ȱ���� �������� ��ȸ
/// 
/// ������� �����ϴ� Ʈ�� ����
/// 
/// ���� ��ȸ : PLR (ǥ�� -> L ��ȸ -> R ��ȸ)
/// ���� ��ȸ : LPR (L ��ȸ -> ǥ�� -> R ��ȸ)
/// ���� ��ȸ : LRP (L ��ȸ -> R ��ȸ -> ǥ��)
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
namespace P28
{

    class node
    {
    public:
        int value;
        node* left;
        node* right;

        node() : value(0), left(nullptr), right(nullptr) {}
        node(int input)
        {
            value = input;
            left = nullptr;
            right = nullptr;
        }
    };

    class tree
    {
    public:
        node* root;

        tree(int input)
        {
            root = new node(input);
        };

        void Insert(const int& input)
        {
            queue<node*> q;
            q.push(root);

            while (!q.empty())
            {
                node* current = q.front();
                q.pop();

                if (current->left == nullptr)
                {
                    current->left = new node(input);
                    return;
                }
                else
                {
                    q.push(current->left);
                }

                if (current->right == nullptr)
                {
                    current->right = new node(input);
                    return;
                }
                else
                {
                    q.push(current->right);
                }
            }
        }

        // ���� ��ȸ p l r
        void preorderTraversal(const node* nowNode, string& currString)
        {
            if (!nowNode) return;

            // 1. ���� ����� ���� ������
            currString += to_string(nowNode->value);
            currString.push_back(' ');

            // 2. ���ʰ� ������ ������� Ž��
            if (nowNode->left != nullptr)
                preorderTraversal(nowNode->left, currString);
            if (nowNode->right != nullptr)
                preorderTraversal(nowNode->right, currString);
        }

        // ���� ��ȸ l p r
        void inorderTraversal(const node* nowNode, string& currString)
        {
            if (!nowNode) return;

            // 2. ���ʰ� ������ ������� Ž��
            if (nowNode->left != nullptr)
                inorderTraversal(nowNode->left, currString);


            // 1. ���� ����� ���� ������
            currString += to_string(nowNode->value);
            currString.push_back(' ');


            if (nowNode->right != nullptr)
                inorderTraversal(nowNode->right, currString);
        }

        // ���� ��ȸ l r p
        void postorderTraversal(const node* nowNode, string& currString)
        {
            if (!nowNode) return;

            // 2. ���ʰ� ������ ������� Ž��
            if (nowNode->left != nullptr)
                postorderTraversal(nowNode->left, currString);

            if (nowNode->right != nullptr)
                postorderTraversal(nowNode->right, currString);
            
            // 1. ���� ����� ���� ������
            currString += to_string(nowNode->value);
            currString.push_back(' ');
        }

        ~tree()
        {
            freeNode(root);
        }

        void freeNode(node* nowNode)
        {
            if (nowNode == nullptr) return;
            freeNode(nowNode->left);
            freeNode(nowNode->right);
            delete nowNode;
        }
    };

    vector<string> solution(vector<int> nodes)
    {
        vector<string> answer;

        tree nowTree(nodes[0]);
        for (auto it = nodes.begin() + 1; it != nodes.end(); ++it)
        {
            nowTree.Insert(*it);
        }

        string pre;
        string in;
        string post;

        nowTree.preorderTraversal(nowTree.root, pre);
        nowTree.inorderTraversal(nowTree.root, in);
        nowTree.postorderTraversal(nowTree.root, post);

        answer.push_back(pre);
        answer.push_back(in);
        answer.push_back(post);
        

        return answer;
    }
}

namespace P28_arr
{
    string Preorder(vector<int> nodes, int idx)
    {
        if (idx < nodes.size())
        {
            string ret = to_string(nodes[idx]) + " ";
            ret += Preorder(nodes, idx * 2 + 1);
            ret += Preorder(nodes, idx * 2 + 2);
            
            return ret;
        }
        return "";
    }

    string Inorder(vector<int> nodes, int idx)
    {
        if (idx < nodes.size())
        {
            string ret;
            ret += Inorder(nodes, idx * 2 + 1);
            ret += to_string(nodes[idx]) + " ";
            ret += Inorder(nodes, idx * 2 + 2);

            return ret;
        }
        return "";
    }

    string Postorder(vector<int> nodes, int idx)
    {
        if (idx < nodes.size())
        {
            string ret;
            ret += Postorder(nodes, idx * 2 + 1);
            ret += Postorder(nodes, idx * 2 + 2);
            ret += to_string(nodes[idx]) + " ";

            return ret;
        }
        return "";
    }
    // TODO: �迭 ��� Ʈ�� ��ȸ ���� ����
    vector<string> solution2(vector<int> nodes)
    {
        vector<string> answer;

        // 1. ���� ��ȸ
        string preorder = Preorder(nodes, 0);
        answer.push_back(preorder);
        // 2. ���� ��ȸ
        string inorder = Inorder(nodes, 0);
        answer.push_back(inorder);

        // 3. ���� ��ȸ;
        string postorder = Postorder(nodes, 0);
        answer.push_back(postorder);


        return answer;
    }
}

//int main()
//{
//    vector<string> result = P28_arr::solution2({ 1,2,3,4,5,6,7 });
//
//    for(string re : result)
//        cout << re << endl;
//}