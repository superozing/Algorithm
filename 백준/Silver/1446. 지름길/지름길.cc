#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

constexpr int INF = 1e9;

struct vtx
{
    int dist;
    int node;
};

struct cmp
{
    bool operator()(vtx& a, vtx& b)
    {
        return a.dist > b.dist;
    }
};

class Boj
{
public:
    int N; // 지름길의 개수
    int D; // 고속도로의 길이

    vector<vector<vtx>> graph;
    vector<int> d;

    void input()
    {
        cin >> N >> D;

        graph.resize(10000);
        d.resize(10000, INF);
        for (int i = 0; i < N; ++i)
        {
            int start = 0;
            vtx v{};
            cin >> start >> v.node >> v.dist;
            graph[start].push_back(v);
        }
    }

    void progress()
    {
        priority_queue<vtx, vector<vtx>, cmp> pq;

        for (int i = 0; i < D + 1; ++i)
        {
            d[i] = i;
            pq.push({ i, i });
        }

        while (!pq.empty())
        {

            vtx cur = pq.top();
            pq.pop();
            int curNode = cur.node;
            int dist = cur.dist;

            if (d[curNode] < dist) continue;

            for (int i = 0; i < graph[curNode].size(); ++i)
            {
                int nextNode = graph[curNode][i].node;
                int nextDist = graph[curNode][i].dist + dist;

                // 모든 이후 인덱스를 최소값으로 갱신
                for (int j = 0; j < D - nextNode + 1; ++j)
                {
                    if (d[nextNode + j] > nextDist + j)
                    {
                        d[nextNode + j] = nextDist + j;
                        pq.push({ nextDist + j, nextNode + j });
                    }
                }
            }
        }

        cout << d[D];
    }
};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}
