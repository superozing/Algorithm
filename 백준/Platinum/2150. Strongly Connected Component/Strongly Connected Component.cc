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
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Boj
{
private:
    int V, E; // 정점, 간선

    vector<vector<int>> edges;
    vector<vector<int>> scc;

    vector<bool> finished;

    int id;
    vector<int> d;

    stack<int> s;

public:
    void input()
    {
        cin >> V >> E;

        edges.resize(V + 1);
        d.resize(V + 1);
        finished.resize(V + 1);

        int s, d;
        for (int i = 0; i < E; ++i)
        {
            cin >> s >> d;
            edges[s].push_back(d);
        }

    }

    void progress()
    {
        for (int i = 1; i <= V; ++i)
        {
            // 방문하지 않은 정점일 경우
            if (d[i] == 0)
                dfs(i);
        }

        cout << scc.size() << endl;

        for (auto& v : scc)
            sort(v.begin(), v.end());

        sort(scc.begin(), scc.end(), Boj());

        for (auto& v : scc)
        {
            for (auto i : v)
                cout << i << " ";
            cout << -1 << endl;
        }

    }

    bool operator ()(vector<int>& a, vector<int>& b)
    {
        return a.front() < b.front();
    }

private:

    int dfs(int x)
    {
        d[x] = ++id;

        s.push(x);

        int parent = d[x];

        for (int i = 0; i < edges[x].size(); ++i)
        {
            int y = edges[x][i];

            if (d[y] == 0)
                parent = min(parent, dfs(y));
            else if (!finished[y])
                parent = min(parent, d[y]);
        }

        // 부모 노드가 자기 자신인 경우 -> 사이클 발생
        if (parent == d[x])
        {
            vector<int> v;
            while (true)
            {
                int t = s.top();
                s.pop();
                v.push_back(t);

                finished[t] = true; // 사이클이 발생한 방문 노드에 대한 방문 처리

                if (t == x)
                    break;
            } 

            scc.push_back(v);
        }

        return parent;
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


