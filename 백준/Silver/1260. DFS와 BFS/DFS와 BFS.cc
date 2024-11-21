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

class Boj
{
private:
    int N, M; // 정점 개수, 간선 개수
    int V; // 시작 정점

    vector<vector<int>> e;

    vector<bool> visited;

public:

    void input()
    {
        cin >> N >> M >> V;

        e.resize(N + 1);
        visited.resize(N + 1);

        int a, b;
        while (M--)
        {
            cin >> a >> b;
            e[a].push_back(b);
            e[b].push_back(a);
        }

        for (auto& it : e)
            sort(it.begin(), it.end());
    }

    void progress()
    {
        dfs(V);

        for (int i = 0; i < visited.size(); ++i)
            visited[i] = false;

        cout << endl;

        bfs(V);
    }

private:

    void dfs(int V)
    {
        if (visited[V] == true)
            return;
        
        cout << V << " ";
        visited[V] = true;

        for (int it : e[V])
            dfs(it);
    }


    void bfs(int V)
    {
        queue<int> q;

        q.push(V);

        visited[V] = true;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            cout << cur << " ";

            for (int it : e[cur])
            {
                if (visited[it] == false)
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }

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

