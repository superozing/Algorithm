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

struct edge
{
    int dest;
    int cost;
};

class Boj
{
private:
    int N;
    vector<vector<edge>> edges;

    vector<bool> visited;


    int maxLength = 0;

public:

    void input()
    {
        cin >> N;

        edges.resize(N + 1);
        visited.resize(N + 1);
        
        int a, b, c;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> a >> b >> c;
            edges[a].push_back({ b, c });
        }
    }

    void progress()
    {
        visited[1] = true;
        dfs(1);

        cout << maxLength;
    }

private:

    int dfs(int curNode)
    {
        // - 반환값(부모 노드로 반환할 값): 현재 노드들의 자식 길이 중 가장 긴 것을 반환
        // - 현재 노드를 거쳐가는 최대값: 현재 노드들의 자식 길이 중 가장 긴 두 개를 합친 것
        // 첫 번째로 큰 길이, 두 번째로 큰 길이
        int firstLength = 0, secondLength = 0;

        for (edge& e : edges[curNode])
        {
            if (!visited[e.dest])
            {
                visited[e.dest] = true;

                int cur = e.cost + dfs(e.dest);

                if (cur > firstLength)
                {
                    secondLength = firstLength;
                    firstLength = cur;
                }
                else if (cur > secondLength)
                {
                    secondLength = cur;
                }

                visited[e.dest] = false;
            }
        }

        // 최대값 갱신
        maxLength = max(maxLength, firstLength + secondLength);

        return firstLength;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj{};
    boj.input();
    boj.progress();

    return 0;
}

