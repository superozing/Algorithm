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
#include <cmath>

using namespace std;

struct pos
{
    int x, y;
};

class Boj
{
private:
    int N;
    vector<pos> v;

public:

    bool operator() (pos& a, pos& b)
    {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    }

    void input()
    {
        cin >> N;
        v.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> v[i].x >> v[i].y;
    }

    void progress()
    {
        sort(v.begin(), v.end(), Boj());
        for (auto& it : v)
            printf("%d %d\n", it.x, it.y);
    }

private:

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

