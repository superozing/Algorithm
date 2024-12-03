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
    int d, w;
};

struct cmp
{
    bool operator() (edge& a, edge& b)
    {
        return a.w > b.w;
    }
};

class Boj
{
private:
    int V, E; // 정점 개수, 간선 개수
    int K; // 시작 정점의 번호

    vector<vector<edge>> edges;

public:

    void input()
    {
        cin >> V >> E >> K;
        edges.resize(V + 1);

        int a, b, w;
        while (E--)
        {
            cin >> a >> b >> w;
            edges[a].push_back({ b, w });
        }
    }

    void progress()
    {
        priority_queue<edge, vector<edge>, cmp> pq;
        vector<int> dist(V + 1, 1e9);

        pq.push({ K, 0 });
        dist[K] = 0;

        while (!pq.empty())
        {
            edge cur = pq.top();
            pq.pop();

            if (dist[cur.d] > cur.w)
                continue;

            for (int i = 0; i < edges[cur.d].size(); ++i)
            {
                edge next = edges[cur.d][i];
                next.w += cur.w;

                if (dist[next.d] > next.w)
                {
                    dist[next.d] = next.w;
                    pq.push(next);
                }
            }
        }

        for (int i = 1; i < dist.size(); ++i)
        {
            dist[i] != 1e9 ? 
                cout << dist[i] << endl : cout << "INF" << endl;
        }
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

