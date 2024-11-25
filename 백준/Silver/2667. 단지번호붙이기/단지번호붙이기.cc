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
    int N; // NxN grid
    vector<string> grid;

public:

    void input()
    {
        cin >> N;

        grid.resize(N);
        for (int i = 0; i < grid.size(); ++i)
            cin >> grid[i];
    }

    void progress()
    {
        vector<int> answer;

        for (int y = 0; y < grid.size(); ++y)
        for (int x = 0; x < grid[0].size(); ++x)
            if (grid[y][x] == '1')
                answer.push_back(bfs({ y, x }));

        cout << answer.size() << endl;

        sort(answer.begin(), answer.end());

        for (int it : answer)
            cout << it << endl;
    }

private:

    int dy[4]{ 0, 1, 0, -1 };
    int dx[4]{ 1, 0, -1, 0 };

    int bfs(pos s)
    {
        int cnt = 0;
        queue<pos> q;

        q.push(s);
        
        // visited 처리
        grid[s.y][s.x] = '0';

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            ++cnt;

            for (int i = 0; i < 4; ++i)
            {
                pos next = cur;
                next.y += dy[i];
                next.x += dx[i];

                if (next.y >= 0 && next.y < N &&
                    next.x >= 0 && next.x < N &&
                    grid[next.y][next.x] == '1')
                {
                    grid[next.y][next.x] = '0';
                    q.push(next);
                }
            }
        }

        return cnt;
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

