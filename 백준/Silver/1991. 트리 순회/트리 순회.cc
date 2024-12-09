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
    char l;
    char r;
};

class Boj
{
private:
    int N;
    vector<node> v;

public:

    void input()
    {
        cin >> N;
        v.resize(N);

        char in;
        for (int i = 0; i < N; ++i)
        {
            cin >> in;
            cin >> v[Idx(in)].l;
            cin >> v[Idx(in)].r;
        }
    }

    void progress()
    {
        preOrder('A');
        cout << endl;
        inOrder('A');
        cout << endl;
        postOrder('A');
    }

private:

    inline int Idx(char c)
    {
        return c - 'A';
    }

    void preOrder(char c)
    {
        cout << c;

        if (v[Idx(c)].l != '.')
            preOrder(v[Idx(c)].l);

        if (v[Idx(c)].r != '.')
            preOrder(v[Idx(c)].r);
    }

    void inOrder(char c)
    {
        if (v[Idx(c)].l != '.')
            inOrder(v[Idx(c)].l);
        
        cout << c;

        if (v[Idx(c)].r != '.')
            inOrder(v[Idx(c)].r);
    }

    void postOrder(char c)
    {
        if (v[Idx(c)].l != '.')
            postOrder(v[Idx(c)].l);
        
        if (v[Idx(c)].r != '.')
            postOrder(v[Idx(c)].r);

        cout << c;
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

