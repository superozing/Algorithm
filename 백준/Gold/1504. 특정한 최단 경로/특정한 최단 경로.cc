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
    int dest, weight;
};

struct cmp
{
    bool operator()(edge& a, edge& b)
    {
        return a.weight > b.weight;
    }
};

class Boj
{
private:
    int N, E;
    int V1, V2;

    vector<vector<edge>> edges;

public:

    void input()
    {
        cin >> N >> E;

        edges.resize(N + 1);

        int a, b, w;
        for (int i = 0; i < E; ++i)
        {
            cin >> a >> b >> w;

            // 입력은 양방향 길
            edges[a].push_back({ b, w });
            edges[b].push_back({ a, w });
        }

        cin >> V1 >> V2;
    }

    void progress()
    {
        // 1부터 N번 정점까지 이동해야 해요.(최단거리로)
        // 근데 이제 중간에 주어진 두 정점(V1, V2)을 거치면서 이동해야 해요.
        int path1 = 0, path2 = 0;
        int cur = 0;

        // 그러면 1->V1->V2->N
        while (true)
        {
            cur = Dijkstra(1, V1);
            if (cur == -1)
            {
                path1 = 1e9 * 2;
                break;
            }
            path1 += cur;

            cur = Dijkstra(V1, V2);
            if (cur == -1)
            {
                path1 = 1e9 * 2;
                break;
            }
            path1 += cur;

            cur = Dijkstra(V2, N);
            if (cur == -1)
            {
                path1 = 1e9 * 2;
                break;
            }
            path1 += cur;

            break;
        }

        // 그리고 1->V2->V1->N
        while (true)
        {
            cur = Dijkstra(1, V2);
            if (cur == -1)
            {
                path2 = 1e9 * 2;
                break;
            }
            path2 += cur;

            cur = Dijkstra(V2, V1);
            if (cur == -1)
            {
                path2 = 1e9 * 2;
                break;
            }
            path2 += cur;

            cur = Dijkstra(V1, N);
            if (cur == -1)
            {
                path2 = 1e9 * 2;
                break;
            }
            path2 += cur;

            break;
        }

        cout << (min(path1, path2) != 1e9 * 2 ? min(path1, path2) : -1);
    }

private:

    int Dijkstra(int s, int d)
    {
        vector<int> dist(N + 1, 1e9 * 2);

        priority_queue<edge, vector<edge>, cmp> pq;

        dist[s] = 0;

        pq.push({ s, 0 });

        while (!pq.empty())
        {
            edge cur = pq.top();
            pq.pop();

            for (int i = 0; i < edges[cur.dest].size(); ++i)
            {
                edge next = edges[cur.dest][i];
                next.weight += cur.weight;

                if (dist[next.dest] > next.weight)
                {
                    dist[next.dest] = next.weight;
                    pq.push(next);
                }
            }
        }

        return dist[d] < 1e9 * 2 ? dist[d] : -1;
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

