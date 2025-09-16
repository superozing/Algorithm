#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define endl ('\n')

using namespace std;

struct Node
{
    int dest, cost;
};

struct Cost
{
    int cost;
    vector<int> path;
};

struct Cmp
{
    bool operator() (const Node& a, const Node& b)
    {
        return a.cost > b.cost;
    }
};

constexpr int MAX = 1e9 * 2;

int S, D;
vector<vector<Node>> nodes;
vector<Cost> costs;

void Dijkstra()
{
    costs[S].cost = 0;
    costs[S].path.push_back(S);

    priority_queue<Node, vector<Node>, Cmp> pq;
    pq.push({ S, 0 });

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (costs[cur.dest].cost < cur.cost)
            continue;

        for (auto& next : nodes[cur.dest])
        {
            if (costs[next.dest].cost > costs[cur.dest].cost + next.cost)
            {
                costs[next.dest].cost = costs[cur.dest].cost + next.cost;
                costs[next.dest].path = costs[cur.dest].path;
                costs[next.dest].path.push_back(next.dest);

                pq.push({ next.dest, costs[next.dest].cost });
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    nodes.resize(N + 1);
    costs.resize(N + 1, { MAX, vector<int>() });

    for (int i = 0; i < M; ++i)
    {
        int s, d, c;
        cin >> s >> d >> c;
        nodes[s].push_back({ d, c });
    }

    cin >> S >> D;



    Dijkstra();



    cout << costs[D].cost << endl;
    cout << costs[D].path.size() << endl;

    for (int i : costs[D].path)
        cout << i << ' ';

    return 0;
}
