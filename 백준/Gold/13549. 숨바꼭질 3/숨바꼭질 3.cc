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

constexpr int MAX = 100000;

struct pos
{
    int x, sec;
};

class Boj
{
private:
    int N, K; // 수빈이의 위치, 동생의 위치

    vector<int> visited;

public:

    void input()
    {
        cin >> N >> K;
        visited.resize(MAX + 1, MAX);
    }

    void progress()
    {
        queue<pos> q;

        q.push({ N, 0 });
        visited[N] = 0;

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            if (cur.x * 2 <= MAX && visited[cur.x * 2] > cur.sec)
            {
                visited[cur.x * 2] = cur.sec;
                q.push({ cur.x * 2, cur.sec });
            }

            if (cur.x + 1 <= K && visited[cur.x  + 1] > cur.sec + 1)
            {
                visited[cur.x + 1] = cur.sec + 1;
                q.push({ cur.x + 1, cur.sec + 1 });
            }

            if (cur.x - 1 >= 0 && visited[cur.x - 1] > cur.sec + 1)
            {
                visited[cur.x - 1] = cur.sec + 1;
                q.push({ cur.x - 1, cur.sec + 1});
            }
        }

        cout << visited[K];
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

