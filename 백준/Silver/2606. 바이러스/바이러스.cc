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

struct node
{
    int n, c;
};

class Boj
{
private:
    int N; // 컴퓨터의 수
    int M; // edge 수

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
        queue<int> q;

        q.push(1);
        visited[1] = true;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int val : edges[cur])
            {
                if (!visited[val])
                {
                    visited[val] = true;
                    q.push(val);
                }
            }
        }

        int answer = 0;

        for (bool b : visited)
        {
            if (b)
                ++answer;
        }

        // 1번 컴퓨터를 통해 걸리게 되는 컴퓨터의 수
        cout << answer - 1;
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

