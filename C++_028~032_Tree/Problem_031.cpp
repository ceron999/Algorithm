/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/77486
/// 다단계 칫솔 판매
/// 
/// 못했던 점
/// 1. insert와 find 등을 dfs방식으로 너무 많이 순회하는 방식 구현
/// 2. unordered_map.count(key)가 키가 존재하면 1 아니면 0을 반환하는 함수인데 이걸 몰랐음
/// 3. tree에 unordered map<이름, 이름에 해당하는 노드 위치>을 통해 find 기능을 늘릴 수 있음을 잘 알지 못함
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
            // parent, new node 생성
            SellerNode* parent = (parentName == "-") ? root : nodeMap[parentName];
            SellerNode* newNode = new SellerNode(insertName, parent);;

            // 부모노드의 child에 new node 추가 후 map에 저장
            parent->childs.push_back(newNode);
            nodeMap[insertName] = newNode;
        }

        SellerNode* Find(const string &name)
        {
            return nodeMap.count(name) ? nodeMap[name] : nullptr;
        }

        void UpdateAmount(int nowAmount, SellerNode* currNode)
        {
            // nowAmount가 0이거나 현재 노드가 null이라면 그냥 제거
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

        // 1. enroll, referral을 활용하여 tree 구조 생성
        SellerTree stree;
        for (int i = 0; i < enroll.size(); i++)
        {
            stree.Insert(enroll[i], referral[i]);
        }

        // 2. seller과 amount를 stree에 업데이트
        for (int i = 0; i < seller.size(); i++)
        {
            // seller[i]를 이름으로 하는 노드를 찾아 parnet 순으로 업데이트한다
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