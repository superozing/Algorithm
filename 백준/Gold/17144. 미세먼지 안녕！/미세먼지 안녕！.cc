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
    int R, C;   // 행과 열 개수
    int T;      // T초 후

    int airPurifierRow = -1;

    vector<vector<int>> grid;
    vector<vector<int>> nextGrid;

public:

    void input()
    {
        cin >> R >> C >> T;
        grid.resize(R, vector<int>(C));
        nextGrid.resize(R, vector<int>(C));

        for (int y = 0; y < R; ++y)
        for (int x = 0; x < C; ++x)
        {
            cin >> grid[y][x];

            if (airPurifierRow == -1 && grid[y][x] == -1)
                airPurifierRow = y;
        }
    }

    void progress()
    {
        while (T--)
        {
            // 1. 확산
            spread();

            // 2. 공기청정기
            airPurifier();
        }

        int answer = 0;

        for (int y = 0; y < R; ++y)
        for (int x = 0; x < C; ++x)
            answer += grid[y][x];

        answer += 2;

        cout << answer;
    }

private:

    int dy[4]{ 0, 1, 0, -1 };
    int dx[4]{ -1, 0, 1, 0 };

    void spread()
    {
        nextGrid = grid;

        for (int y = 0; y < R; ++y)
        for (int x = 0; x < C; ++x)
        {
            // 공기청정기 또는 먼지가 없는 경우
            if (grid[y][x] <= 0)
                continue;

            int divideDust = grid[y][x] / 5;

            for (int i = 0; i < 4; ++i)
            {
                pos next{ y + dy[i], x + dx[i] };

                if (next.y >= 0 && next.y < R &&
                    next.x >= 0 && next.x < C &&
                    grid[next.y][next.x] != -1)
                {
                    nextGrid[next.y][next.x] += divideDust;
                    nextGrid[y][x] -= divideDust;
                }
            }
        }

        grid = nextGrid;
    }

    void airPurifier()
    {
        // 1. 위(y 0까지)->오른(x C까지)->아래(y airPurifierRow까지)-> 왼(x 0까지)
        for (int y = airPurifierRow - 1; y > 0; --y)
            grid[y][0] = grid[y - 1][0];

        for (int x = 0; x < C - 1; ++x)
            grid[0][x] = grid[0][x + 1];

        for (int y = 0; y < airPurifierRow; ++y)
            grid[y][C - 1] = grid[y + 1][C - 1];

        for (int x = C - 1; x > 1; --x)
            grid[airPurifierRow][x] = grid[airPurifierRow][x - 1];

        grid[airPurifierRow][1] = 0;

        // 2. 아래(y R까지) -> 오른 (x C까지) -> 위 (y airPurifierRow + 1까지 -> 왼 (x 0까지)
        for (int y = airPurifierRow + 2; y < R - 1; ++y)
            grid[y][0] = grid[y + 1][0];

        for (int x = 0; x < C - 1; ++x)
            grid[R - 1][x] = grid[R - 1][x + 1];

        for (int y = R - 1; y > airPurifierRow + 1; --y)
            grid[y][C - 1] = grid[y - 1][C - 1];

        for (int x = C - 1; x > 1; --x)
            grid[airPurifierRow + 1][x] = grid[airPurifierRow + 1][x - 1];
    
        grid[airPurifierRow + 1][1] = 0;

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

