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

struct body
{
    int w, h, c = 0;
};

class Boj
{
private:
    int N;

    vector<body> v;

public:

    void input()
    {
        cin >> N;
        v.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> v[i].w >> v[i].h;
    }

    void progress()
    {
        for (int i = 0; i < N; ++i)
        {
            body& cur = v[i];

            for (int j = 0; j < N; ++j)
            {
                if (i == j)
                    continue;

                // 졌을 경우 ++
                if (cur.w < v[j].w && cur.h < v[j].h)
                    ++cur.c;
            }
        }

        for (int i = 0; i < N; ++i)
            printf("%d ", v[i].c + 1);
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

