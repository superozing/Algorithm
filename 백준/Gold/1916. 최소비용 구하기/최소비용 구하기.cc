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

struct edge
{
    int to, cost;
};

struct cmp
{
    bool operator() (edge& a, edge& b)
    {
        return a.cost > b.cost;
    }
};

class Boj
{
private:
    int N, M; // 도시 개수, 버스 개수
    int S, D; // 시작 지점, 도착 지점

    vector<vector<edge>> edges;

    priority_queue<edge, vector<edge>, cmp> pq;

public:

    void input()
    {
        cin >> N >> M;
        edges.resize(N + 1);
        
        int s, e, w;
        for (int i = 0; i < M; ++i)
        {
            cin >> s >> e >> w;
            edges[s].push_back({ e, w });
        }

        cin >> S >> D;
    }

    void progress()
    {
        vector<int> d(N + 1, 1e9);

        d[S] = 0;

        pq.push({ S, 0 });

        while (!pq.empty())
        {
            auto cNode = pq.top();
            pq.pop();

            if (d[cNode.to] < cNode.cost)
                continue;

            for (int i = 0; i < edges[cNode.to].size(); ++i)
            {
                auto& cEdge = edges[cNode.to][i];
                if (d[cEdge.to] > d[cNode.to] + cEdge.cost)
                {
                    d[cEdge.to] = d[cNode.to] + cEdge.cost;
                    pq.push(cEdge);
                }
            }
        }

        cout << d[D];
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

