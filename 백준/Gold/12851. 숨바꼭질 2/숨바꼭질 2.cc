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

    vector<int> minTime;

public:

    void input()
    {
        cin >> N >> K;

        minTime.resize(100001, 1e9);
    }

    void progress()
    {
        int answer = 0; // 개수
        
        queue<pos> q;

        q.push({ N, 0 });

        minTime[N] = 0;

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            if (cur.x == K)
                ++answer;

            cur.c++;

            pos next = cur;
            next.x += 1;
            if (next.x <= 100000 && minTime[next.x] >= next.c)
            {
                minTime[next.x] = next.c;
                q.push(next);
            }
            
            next = cur;
            next.x -= 1;
            if (next.x >= 0 && minTime[next.x] >= next.c)
            {
                minTime[next.x] = next.c;
                q.push(next);
            }

            next = cur;
            next.x *= 2;
            if (next.x <= 100000 && minTime[next.x] >= next.c)
            {
                minTime[next.x] = next.c;
                q.push(next);
            }
        }

        cout << minTime[K] << endl << answer;
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

