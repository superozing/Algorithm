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

            int idx = Idx(in);
            cin >> v[idx].l;
            cin >> v[idx].r;
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
        int idx = Idx(c);

        cout << c;

        if (v[idx].l != '.')
            preOrder(v[idx].l);

        if (v[idx].r != '.')
            preOrder(v[idx].r);
    }

    void inOrder(char c)
    {
        int idx = Idx(c);

        if (v[idx].l != '.')
            inOrder(v[idx].l);
        
        cout << c;

        if (v[idx].r != '.')
            inOrder(v[idx].r);
    }

    void postOrder(char c)
    {
        int idx = Idx(c);

        if (v[idx].l != '.')
            postOrder(v[idx].l);
        
        if (v[idx].r != '.')
            postOrder(v[idx].r);

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

