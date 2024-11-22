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

struct fr
{
    int i, c;
};

class Boj
{
private:
    int N, M; // 유저 수, 관계 수

    vector<vector<int>> e;

public:

    void input()
    {
        cin >> N >> M;

        e.resize(N + 1);

        int a, b;
        while (M--)
        {
            cin >> a >> b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
    }

    void progress()
    {
        int minWeight = 1e9;
        int answer = 0;

        for (int i = 1; i <= N; ++i)
        {
            int curWeight = bfs(i);
            
            if (minWeight > curWeight)
            {
                minWeight = curWeight;
                answer = i;
            }
        }

        cout << answer;
    }

private:

    int bfs(int start)
    {
        queue<fr> q;
        vector<int> visited(N + 1);

        q.push({ start, 0 });

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            cur.c++;

            for (auto& it : e[cur.i])
            {
                // 방문하지 않은 노드?
                if (visited[it] == 0)
                {
                    visited[it] = cur.c;
                    q.push({ it, cur.c });
                }
            }
        }

        int sum = 0;

        for (int i : visited)
            sum += i;

        return sum;
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

