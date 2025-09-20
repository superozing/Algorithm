#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define endl ('\n')

using namespace std;

vector<vector<int>> grid(10, vector<int>(10));
vector<vector<bool>> visitedY(10, vector<bool>(10));
vector<vector<bool>> visitedX(10, vector<bool>(10));
vector<vector<bool>> visitedGroup(10, vector<bool>(10));

void FindNextIndex(int& ny, int& nx)
{
    bool findZero = false;
    for (int y = 1; y <= 9; ++y)
    for (int x = 1; x <= 9; ++x)
    {
        if (grid[y][x] == 0)
        {
            // 현재 위치가 아닌 다음 위치를 찾아야 해요.
            if (!findZero)
            {
                findZero = true;
                continue;
            }

            ny = y;
            nx = x;
            return;
        }
    }

    // 마지막 인덱스일 경우 탐색 종료
    ny = -1; 
    nx = -1;
}

int GetGroupIndex(int y, int x)
{
    --y /= 3;
    --x /= 3;

    return 3 * y + x;
}

// 종료 여부를 반환
bool Backtracking(int cy, int cx)
{
    // 종료 조건
    if (cy == -1 && cx == -1)
        return true;

    // 현재 cy cx에 넣을 수 있는 숫자가 없으면 return false 해야 해요.
    // 현재 어떤 그룹에 속해있는지 알아야 해요.
    int ny, nx;
    FindNextIndex(ny, nx);
    int curGroup = GetGroupIndex(cy, cx);

    for (int i = 1; i <= 9; ++i)
    {
        int& cur = grid[cy][cx];

        if (!visitedY[cy][i] && !visitedX[cx][i] && !visitedGroup[curGroup][i])
        {
            visitedY[cy][i] = true;
            visitedX[cx][i] = true;
            visitedGroup[curGroup][i] = true;
            cur = i;

            if (Backtracking(ny, nx))
                return true;

            visitedY[cy][i] = false;
            visitedX[cx][i] = false;
            visitedGroup[curGroup][i] = false;
            cur = 0;
        }
    }

    return false;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    for (int y = 1; y <= 9; ++y)
    for (int x = 1; x <= 9; ++x)
    {
        char c;
        cin >> c;
        grid[y][x] = c - '0';
    }

    // 입력 받았을 때 visited 들 초기화를 먼저 해주어야 해요.
    int sy = -1, sx = -1;
    for (int y = 1; y <= 9; ++y)
    for (int x = 1; x <= 9; ++x)
    {
        int curNum = grid[y][x];
        if (curNum == 0)
        {
            // 시작 지점 설정
            if (sy == -1)
            {
                sy = y;
                sx = x;
            }

            continue;
        }

        visitedY[y][curNum] = true;
        visitedX[x][curNum] = true;
        visitedGroup[GetGroupIndex(y, x)][curNum] = true;
    }

    Backtracking(sy, sx);

    // 출력해야 해요.

    for (int y = 1; y <= 9; ++y)
    {
        for (int x = 1; x <= 9; ++x)
            cout << grid[y][x];
        cout << endl;
    }

    return 0;
}
