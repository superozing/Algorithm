#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct tEdge
{
    int dest, cost;
};

struct cmp
{
    bool operator() (tEdge& a, tEdge& b)
    {
        return a.cost > b.cost;
    }
};

int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;
    
    // 다익스트라 후 max 값을 가진 노드의 개수 구하기.
    // 항상 1번 노드를 기준으로 시작
    
    vector<vector<int>> edges(n + 1);
    
    for (vector<int>& e : edge)
    {
        edges[e[0]].push_back(e[1]);
        edges[e[1]].push_back(e[0]);
    }
    
    //for (vector<int>& e : edges)
    //{
    //    for (int i : e)
    //        cout << i << " ";
    //    
    //    cout << endl << endl;
    //}
    
    
    vector<int> dist(n + 1, 1e9);
    dist[1] = 0;
    
    priority_queue<tEdge, vector<tEdge>, cmp> pq;
    
    pq.push({1, 0});
    
    while (!pq.empty())
    {
        tEdge cur = pq.top();
        pq.pop();
        
        if (dist[cur.dest] < cur.cost)
            continue;
        
        for (int next : edges[cur.dest])
        {
            if (dist[next] > cur.cost + 1)
            {
                dist[next] = cur.cost + 1;
                pq.push({next, dist[next]});
            }
        }
    }
    
    int maxVal = 0;
    for (int i = 0; i < dist.size(); ++i)
    {
        if (maxVal < dist[i] && dist[i] != 1e9)
            maxVal = dist[i];
    }

    return count(begin(dist), end(dist), maxVal);
}





















