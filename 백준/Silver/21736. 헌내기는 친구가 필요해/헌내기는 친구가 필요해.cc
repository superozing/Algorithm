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
    int Y, X;

    vector<string> grid;
    vector<vector<bool>> visited;

    int iy;
    int ix;

public:

    void input()
    {
        cin >> Y >> X;

        grid.resize(Y, string(X, ' '));
        visited.resize(Y, vector<bool>(X));

        for (int i = 0; i < Y; ++i)
        for (int j = 0; j < X; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'I')
            {
                iy = i;
                ix = j;
            }
        }
    }

    int dy[4]{ 0, -1, 0, 1 };
    int dx[4]{ -1, 0, 1, 0 };

    void progress()
    {
        int answer = 0;
        queue<pos> q;

        q.push({ iy, ix});

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i)
            {
                pos np = cur;
                np.y += dy[i];
                np.x += dx[i];

                if (np.x >= 0 && np.x < X &&
                    np.y >= 0 && np.y < Y &&
                    visited[np.y][np.x] == false && grid[np.y][np.x] != 'X')
                {
                    visited[np.y][np.x] = true;
                    
                    if (grid[np.y][np.x] == 'P')
                        ++answer;

                    q.push(np);
                }
            }
        }

        answer == 0 ? cout << "TT" : cout << answer;
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

