///////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cmath>

using namespace std;

#define endl ("\n")

struct node
{
    int value;
    node* lChild = nullptr;
    node* rChild = nullptr;

    node() { }
    node(int in)
        : value(in)
    {
    }

    void insert(int in)
    {
        // 입력 값이 현재 value보다 작을 경우
        if (in < value)
        {
            // 왼 쪽 자식이 있다면 왼 쪽 자식에게 insert 재귀 호출
            if (lChild != nullptr)
                lChild->insert(in);
            // 왼 쪽 자식이 없다면 왼 쪽 자식으로 in 달아주기
            else
                lChild = new node(in);
        }
        else
        {
            // 오른 쪽 자식이 있다면 오른 쪽 자식에게 insert 재귀 호출
            if (rChild != nullptr)
                rChild->insert(in);
            // 오른 쪽 자식이 없다면 오른 쪽 자식으로 in 달아주기
            else
                rChild = new node(in);
        }
    }
};

class Boj
{
private:
    node* rootNode;

public:

    void input()
    {
        int in;
        cin >> in;
        rootNode = new node(in);

        while (cin >> in)
            rootNode->insert(in);
    }

    void progress()
    {
        dfs(rootNode);
    }

private:

    void dfs(node* n)
    {
        // 왼 쪽 자식 탐색
        if (n->lChild != nullptr)
            dfs(n->lChild);
        // 오른 쪽 자식 탐색
        if (n->rChild != nullptr)
            dfs(n->rChild);

        cout << n->value << endl;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

