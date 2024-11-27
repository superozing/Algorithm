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

struct pos
{
    int y, x;
};

class Boj
{
private:
    int N, M; // 사다리 수, 뱀 수

    vector<int> visited;
    vector<int> snakeLadder;
public:

    void input()
    {
        cin >> N >> M;
        visited.resize(100 + 1, 1e9);
        snakeLadder.resize(100 + 1);

        N += M;
        int a, b;
        while (N--)
        {
            cin >> a >> b;
            snakeLadder[a] = b;
        }
    }

    void progress()
    {
        // 근데 이게 뱀을 밟는 경우의 수도 고려를 해야 해요.

        queue<int> q;

        q.push(1);
        visited[1] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int i = 1; i <= 6; ++i)
            {
                int next = cur + i;

                if (next > 100 || visited[next] <= visited[cur] + 1)
                    continue;

                // 지름길 있나요?
                if (snakeLadder[next] != 0)
                {
                    if (visited[snakeLadder[next]] <= visited[cur] + 1)
                        continue;

                    visited[snakeLadder[next]] = visited[cur] + 1;
                    visited[next] = visited[cur] + 1;
                    q.push(snakeLadder[next]);
                }
                else
                {
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                }
            }
        }

        cout << visited[100];
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

