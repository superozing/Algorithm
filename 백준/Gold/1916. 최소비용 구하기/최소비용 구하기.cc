// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;
constexpr auto INF = 100000000;

struct vtx
{
    int cost;
    int node;
};

struct cmp
{
    bool operator()(vtx& a, vtx& b)
    {
        return a.cost > b.cost;
    }
};

class Boj
{
public:
    int N; // 도시 개수
    int M; // 버스 개수
    int S; // 시작 정점의 번호
    int D; // 끝 정점의 번호

    vector<vector<vtx>> graph;
    vector<int> dist;

    void input()
    {
        cin >> N >> M;
        graph.resize(N);
        dist.resize(N, INF);

        for (int i = 0; i < M; ++i)
        {
            int cur;
            cin >> cur;
            vtx v;
            cin >> v.node >> v.cost;
            --v.node;
            graph[cur - 1].push_back(v);
        }

        cin >> S >> D;
        dist[S - 1] = 0;
    }

    void progress()
    {
        priority_queue<vtx, vector<vtx>, cmp> q;
        q.push({ 0, S - 1 });

        while (!q.empty())
        {
            vtx v = q.top();
            q.pop();
            int cost = v.cost;
            int idx = v.node;
            
            if (dist[idx] < cost)
                continue;
            
            for (int i = 0; i < graph[idx].size(); ++i)
            {
                vtx nextv = graph[idx][i];
                if (cost + graph[idx][i].cost < dist[graph[idx][i].node])
                {
                    dist[graph[idx][i].node] = cost + graph[idx][i].cost;
                    q.push({ cost + graph[idx][i].cost , graph[idx][i].node });
                }
            }
        }

        cout << dist[D - 1];
    }


};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();


    return 0;
}
