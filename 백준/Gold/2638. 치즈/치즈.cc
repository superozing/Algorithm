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

    vector<vector<int>> grid;
    vector<vector<bool>> outline;

public:

    void input()
    {
        cin >> Y >> X;
        grid.resize(Y, vector<int>(X));
        outline.resize(Y, vector<bool>(X));

        for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)
            cin >> grid[i][j];
    }

    void progress()
    {
        int answer = 0;

        while (!isMelted())
        {
            ++answer;
            setOuterLine();
            meltCheese();
        }
        
        cout << answer;
    }

private:

    int dy[4]{ 0, 1, 0, -1 };
    int dx[4]{ 1, 0, -1, 0 };


    bool isMelted()
    {
        bool endFlag = true;

        for (int i = 0; i < Y; ++i)
        {
            for (int j = 0; j < X; ++j)
            {
                if (grid[i][j] == 1)
                {
                    endFlag = false;
                    break;
                }
            }

            if (!endFlag)
                break;
        }

        return endFlag;
    }

    void setOuterLine()
    {
        queue<pos> q;

        for (int i = 0; i < Y; ++i)
        for (int j = 0; j < X; ++j)
            outline[i][j] = false;

        for (int i = 0; i < Y; ++i)
        {
            q.push({ i, 0 });
            outline[i][0] = true;
            q.push({ i, X - 1 });
            outline[i][X - 1] = true;
        }
        for (int i = 0; i < X; ++i)
        {
            q.push({ 0, i });
            outline[0][i] = true;
            q.push({ Y - 1, i });
            outline[Y - 1][i] = true;
        }

        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                pos next = cur;
                next.y += dy[i];
                next.x += dx[i];

                if (next.y >= 0 && next.y < Y &&
                    next.x >= 0 && next.x < X &&
                    !outline[next.y][next.x] && grid[next.y][next.x] != 1)
                {
                    outline[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }
    }

    void meltCheese()
    {
        // 만 번 정도는 괜찮겠죠?
        for (int i = 0; i < Y; ++i)
        for (int j = 0; j < X; ++j)
        {
            // 외부인지 판정 -> visited true
            if (grid[i][j] == 1)
            {
                int outerCnt = 0;
                
                // 치즈가 녹은 걸로 set: 0 넣어도 될 듯.
                for (int k = 0; k < 4; ++k)
                {
                    pos cur{ i, j };

                    cur.y += dy[k];
                    cur.x += dx[k];

                    if (cur.y >= 0 && cur.y < Y &&
                        cur.x >= 0 && cur.x < X &&
                        outline[cur.y][cur.x])
                    {
                        ++outerCnt;
                    }
                }

                if (outerCnt >= 2)
                    grid[i][j] = 0;
            }
        }
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

