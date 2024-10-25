//////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

struct edge
{
    int dest;
    int weight;
};

struct cmp
{
    bool operator () (edge& a, edge& b)
    {
        return a.weight > b.weight;
    }
};

class Boj
{
private:
    int V, E; // 정점 개수, 간선 개수
    vector<vector<edge>> edges; // 간선 정보: edges[1].top().dest = 3 은 vtx 1->2의 가중치는 3 
    priority_queue<edge, vector<edge>, cmp> pq;
    vector<bool> visited; // 켜놓은 곳은 이미 방문한 곳(노드 확장 가능)
    
    int minWeight = 0;

public:
    void input()
    {
        cin >> V >> E;
        edges.resize(V + 1);
        visited.resize(V + 1);
        int startVtx = 0;
        edge input{};
        for (int i = 0; i < E; ++i)
        {
            cin >> startVtx >> input.dest >> input.weight;
            edges[startVtx].push_back(input);
            edges[input.dest].push_back({ startVtx , input.weight });
        }
    }

    void progress()
    {

        pq.push({ 1, 0 });

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            //cout << "dest: " << cur.dest << ", weight:" << cur.weight << endl;
            
            if (visited[cur.dest])
                continue;
            
            visited[cur.dest] = true;

            minWeight += cur.weight;
    
            for (int i = 0; i < edges[cur.dest].size(); ++i)
                pq.push(edges[cur.dest][i]);
        }

        cout << minWeight;
    }

private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

