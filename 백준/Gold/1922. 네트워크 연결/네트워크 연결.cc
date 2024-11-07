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
    int a, b, c;
};

class Boj
{
private:
    int N, M;
    vector<pos> edges;
    vector<int> parents;

public:

    bool operator () (pos& a, pos& b)
    {
        return a.c < b.c;
    }

    void input()
    {
        cin >> N >> M;
        parents.resize(N + 1);
        edges.resize(M);
        for (int i = 1; i <= N; ++i)
            parents[i] = i;

        int a, b, c;
        for (int i = 0; i < M; ++i)
        {
            cin >> a >> b >> c;
            edges[i] = { a, b, c };
        }

        sort(edges.begin(), edges.end(), Boj());
    }

    void progress()
    {
        int answer = 0;
        int a, b, c;
        for (auto& edge : edges)
        {
            a = edge.a;
            b = edge.b;
            c = edge.c;

            if (Union(a, b))
                continue;

            answer += c;
        }

        cout << answer;
    }

private:

    bool Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b)
            return true;

        parents[min(a, b)] = max(a, b);
        return false;
    }

    int Find(int a)
    {
        // 부모를 찾은 경우
        if (a == parents[a])
            return a;
    
        return parents[a] = Find(parents[a]);
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

