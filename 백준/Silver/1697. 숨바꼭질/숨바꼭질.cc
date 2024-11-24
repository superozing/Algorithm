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
    int x, c;
};

class Boj
{
private:
    int N, K; // 수빈이의 위치, 동생의 위치

    vector<bool> visited;

public:

    void input()
    {
        cin >> N >> K;

        visited.resize(100001);
    }

    void progress()
    {
        queue<pos> q;

        q.push({ N, 0 });
        visited[N] = true;

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            // 동생의 위치로 이동한 경우
            if (cur.x == K)
            {
                cout << cur.c;
                return;
            }


            if (cur.x - 1 >= 0 && !visited[cur.x - 1])
            {
                q.push({ cur.x - 1, cur.c + 1 });
                visited[cur.x - 1] = true;
            }

            if (cur.x + 1 < visited.size() && !visited[cur.x + 1])
            {
                q.push({ cur.x + 1, cur.c + 1 });
                visited[cur.x + 1] = true;
            }

            if (cur.x * 2 < visited.size() && !visited[cur.x * 2])
            {
                q.push({ cur.x * 2, cur.c + 1 });
                visited[cur.x * 2] = true;
            }
        }

        return;
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

