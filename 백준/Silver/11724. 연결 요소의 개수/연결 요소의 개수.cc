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
    int N, M; // 정점 수, 간선 수

    vector<vector<int>> edges;
    vector<bool> visited;

public:

    void input()
    {
        cin >> N >> M;
        edges.resize(N + 1);
        visited.resize(N + 1);

        int a, b;
        while (M--)
        {
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

    }

    void progress()
    {
        int answer = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (visited[i])
                continue;

            ++answer;

            queue<int> q;

            q.push(i);

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int it : edges[cur])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
        }

        cout << answer;
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

