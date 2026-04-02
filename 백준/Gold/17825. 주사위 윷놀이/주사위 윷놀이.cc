#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int point;
    Node* next;
    Node* shortCut;

    Node(int p, Node* n = nullptr, Node* s = nullptr)
    {
        point = p;
        next = n;
        shortCut = s;
    }
};

Node* root;
Node* finish;

Node* A;
Node* B;
Node* C;
Node* D;

int ret;
vector<int> dice;
vector<int> moveTargetOrder;

void Init()
{
    root = new Node(0);
    finish = new Node(0);

    Node* curr = root;

    Node* point10 = nullptr;
    Node* point20 = nullptr;
    Node* point30 = nullptr;
    Node* point40 = nullptr;
    Node* point25 = new Node(25);

    // 메인 경로 생성: 0 -> 2 -> 4 -> ... -> 40
    for (int i = 1; i <= 20; i++)
    {
        Node* next = new Node(i * 2);
        curr->next = next;
        curr = next;

        switch (curr->point)
        {
        case 10:
            point10 = curr;
            break;
        case 20:
            point20 = curr;
            break;
        case 30:
            point30 = curr;
            break;
        case 40:
            point40 = curr;
            break;
        }
    }

    // 40 다음은 도착 칸
    point40->next = finish;

    // 10 지름길: 10 -> 13 -> 16 -> 19 -> 25
    curr = point10;
    for (int i = 1; i <= 3; i++)
    {
        Node* next = new Node(10 + i * 3); // 13, 16, 19

        if (curr == point10) curr->shortCut = next;
        else curr->next = next;

        curr = next;
    }
    curr->next = point25;

    // 20 지름길: 20 -> 22 -> 24 -> 25
    curr = point20;
    for (int i = 1; i <= 2; i++)
    {
        Node* next = new Node(20 + i * 2); // 22, 24

        if (curr == point20) curr->shortCut = next;
        else curr->next = next;

        curr = next;
    }
    curr->next = point25;

    // 30 지름길: 30 -> 28 -> 27 -> 26 -> 25
    curr = point30;
    for (int i = 1; i <= 3; i++)
    {
        Node* next = new Node(29 - i); // 28, 27, 26

        if (curr == point30) curr->shortCut = next;
        else curr->next = next;

        curr = next;
    }
    curr->next = point25;

    // 공용 경로: 25 -> 30 -> 35 -> 40 -> finish
    curr = point25;

    Node* next30 = new Node(30);
    curr->next = next30;
    curr = next30;

    Node* next35 = new Node(35);
    curr->next = next35;
    curr = next35;

    curr->next = point40;
}

Node* getMovedNode(Node* start, int cnt)
{
    Node* cur = start;

    // 이미 도착한 말은 계속 도착 칸에 머무름
    if (cur == finish) return finish;

    // 첫 칸 이동 시에만 지름길 가능
    if (cur->shortCut != nullptr)
    {
        cur = cur->shortCut;
        cnt--;
    }
    else
    {
        cur = cur->next;
        cnt--;
    }

    // 이후는 next만 따라감
    while (cnt > 0 && cur != finish)
    {
        cur = cur->next;
        cnt--;
    }

    return cur;
}

bool isOccupied(Node* dest, Node* me)
{
    // 도착 칸은 여러 말이 있어도 됨
    if (dest == finish) return false;

    if (me != A && dest == A) return true;
    if (me != B && dest == B) return true;
    if (me != C && dest == C) return true;
    if (me != D && dest == D) return true;

    return false;
}

void go()
{
    if (moveTargetOrder.size() == 10)
    {
        A = root;
        B = root;
        C = root;
        D = root;

        int tempPoint = 0;

        for (int i = 0; i < 10; i++)
        {
            int selectedHorse = moveTargetOrder[i];
            int moveCnt = dice[i];

            Node** horse = nullptr;

            if (selectedHorse == 1) horse = &A;
            else if (selectedHorse == 2) horse = &B;
            else if (selectedHorse == 3) horse = &C;
            else horse = &D;

            Node* dest = getMovedNode(*horse, moveCnt);

            // 다른 말이 있는 칸이면 이 경우의 수는 실패
            if (isOccupied(dest, *horse))
                return;

            *horse = dest;
            tempPoint += dest->point;
        }

        ret = max(ret, tempPoint);
        return;
    }

    for (int i = 1; i <= 4; i++)
    {
        moveTargetOrder.push_back(i);
        go();
        moveTargetOrder.pop_back();
    }
}

int main()
{
    dice.resize(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> dice[i];
    }

    Init();
    go();

    cout << ret;
    return 0;
}