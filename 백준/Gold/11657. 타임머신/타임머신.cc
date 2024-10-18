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

struct edge
{
    int src;
    int dest;
    int w;
};

class Boj
{
private:
    int N; // 도시(정점)
    int M; // 버스(간선)

    // 간선 정보를 저장해요.
    vector<edge> edges;

    vector<long long> dist;

public:
    void input()
    {
        // 벨만 포드의 판단 기준: 그래프 간선에 음수일 경우.
        cin >> N >> M;
        dist.resize(N, INF);
        edges.resize(M);

        for (int i = 0; i < M; ++i)
        {
            cin >> edges[i].src >> edges[i].dest >> edges[i].w;
            --edges[i].src;
            --edges[i].dest;
        }
    }

    void progress()
    {
        dist[0] = 0;
        for (int i = 0; i < N - 1; ++i) // N-1번만 돌아도 전부 최소값이 보장되는 이유는?
        for (edge& e : edges)
        {
            // 출발지 정점에 한 번이라도 값이 입력되어있으면서, 
            // 목적지 정점의 가중치와 비교해서 더한 값이 더 가까운지 비교해요.
                // 더 작다면 목적지 갱신
            if (dist[e.src] != INF)
                dist[e.dest] = min(dist[e.dest], dist[e.src] + e.w);
        }

        for (edge& e : edges)
        {
            // 전부 최소값이 보장되어있는 상태에서, 한번 더 돌 때
            // 만약 dist가 "작아진다면" 음수 사이클이 존재함.
            if (dist[e.src] != INF && dist[e.dest] > dist[e.src] + e.w)
            {
                cout << -1;
                return;
            }
        }

        for (int i = 1; i < N; ++i)
            cout << (dist[i] != INF ? dist[i] : -1) << endl;

    }
};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}
