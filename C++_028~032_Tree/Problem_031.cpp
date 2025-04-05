/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/77486
/// �ٴܰ� ĩ�� �Ǹ�
/// 
/// ���ߴ� ��
/// 1. insert�� find ���� dfs������� �ʹ� ���� ��ȸ�ϴ� ��� ����
/// 2. unordered_map.count(key)�� Ű�� �����ϸ� 1 �ƴϸ� 0�� ��ȯ�ϴ� �Լ��ε� �̰� ������
/// 3. tree�� unordered map<�̸�, �̸��� �ش��ϴ� ��� ��ġ>�� ���� find ����� �ø� �� ������ �� ���� ����
/// </summary>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
namespace P31
{
    class SellerNode
    {
    public:
        string name;
        int amount;
        SellerNode* parent;
        vector<SellerNode*> childs;

        SellerNode(string getName = "", SellerNode* parnetNode = nullptr) 
                : name(getName), amount(0), parent(parnetNode) {}
    };

    class SellerTree
    {
    public:
        SellerNode* root;
        unordered_map<string, SellerNode*> nodeMap;

        SellerTree() { root = new SellerNode("center"); nodeMap["center"] = root; };

        void Insert(const string &insertName,const string &parentName)
        {
            // parent, new node ����
            SellerNode* parent = (parentName == "-") ? root : nodeMap[parentName];
            SellerNode* newNode = new SellerNode(insertName, parent);;

            // �θ����� child�� new node �߰� �� map�� ����
            parent->childs.push_back(newNode);
            nodeMap[insertName] = newNode;
        }

        SellerNode* Find(const string &name)
        {
            return nodeMap.count(name) ? nodeMap[name] : nullptr;
        }

        void UpdateAmount(int nowAmount, SellerNode* currNode)
        {
            // nowAmount�� 0�̰ų� ���� ��尡 null�̶�� �׳� ����
            if (nowAmount == 0 || currNode == nullptr)
                return;

            int sendMoney = nowAmount / 10;
            currNode->amount += (nowAmount - sendMoney);
            UpdateAmount(sendMoney, currNode->parent);
        }


    };

    vector<int> solution(vector<string> enroll, vector<string> referral,
                        vector<string> seller, vector<int> amount) 
    
    {
        vector<int> answer;

        // 1. enroll, referral�� Ȱ���Ͽ� tree ���� ����
        SellerTree stree;
        for (int i = 0; i < enroll.size(); i++)
        {
            stree.Insert(enroll[i], referral[i]);
        }

        // 2. seller�� amount�� stree�� ������Ʈ
        for (int i = 0; i < seller.size(); i++)
        {
            // seller[i]�� �̸����� �ϴ� ��带 ã�� parnet ������ ������Ʈ�Ѵ�
            SellerNode* nowSeller = stree.Find(seller[i]);
            stree.UpdateAmount(amount[i] * 100, nowSeller);
        }
        
        for (string nowSeller : enroll)
        {
            SellerNode* nowNode = stree.Find(nowSeller);
            answer.push_back(nowNode->amount);
        }

        return answer;
    }
}

//int main()
//{
//    vector<string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
//    vector<string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
//    vector<string> seller = { "young", "john", "tod", "emily", "mary" };
//    vector<int> amount = { 12, 4, 2, 5, 10 };
//
//    vector<int> result = P31::solution( enroll, referral, seller, amount );
//
//    for(int i : result)
//        cout << i << " ";
//}