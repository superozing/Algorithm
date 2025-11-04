#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int answer = 1e9;
vector<vector<bool>> grid;

bool CanMove()
{
    for (int line = 0; line < grid.size(); ++line)
    {
        int endPoint = line;
        int depth = 0;
        while (depth < grid[0].size())
        {
            if (endPoint != grid.size() - 1 && grid[endPoint][depth])
                endPoint++;
            else if (endPoint > 0 && grid[endPoint - 1][depth])
                endPoint--;

            depth++;
        }

        if (line != endPoint)
            return false;
    }

    return true;
}

void Backtracking(int lineCount, int startLine, int startPoint)
{
    // 종료 조건: 모든 지점 시작과 끝이 동일한가?
    if (CanMove())
    {
        answer = min(answer, lineCount);
        return;
    }
    else if (lineCount == 3 || lineCount >= answer)
        return;

    for (int line = startLine; line < grid.size() - 1; ++line)
    {
        for (int point = (startLine == line ? startPoint : 0); point < grid[0].size(); ++point)
        {
            if (grid[line][point] || (line > 0 && grid[line - 1][point]) || (line != grid.size() - 1 && grid[line + 1][point]))
                continue;

            grid[line][point] = true;
            Backtracking(lineCount + 1, line, point);
            grid[line][point] = false;
        }
    }

    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    //정답이 3보다 큰 값이거나 불가능하면 -1 출력 -> 백트래킹 해라

    int N, M, H;
    cin >> N >> M >> H;

    // 연결 여부를 저장하는 grid에요.
    grid.resize(N, vector<bool>(H));

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        grid[b - 1][a - 1] = true; // b번 세로선 a 위치는 b + 1번 세로선 a 위치와 이어져있다.
    }

    Backtracking(0, 0, 0);
    
    cout << (answer == 1e9 ? -1 : answer);

    return 0;
}