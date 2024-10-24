#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Boj
{
private:
    int N, M; // NxM

    vector<string> grid;
    vector<vector<int>> visited;

    int accCount = 0;

public:

    void input()
    {
        cin >> N >> M;
        grid.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> grid[i];

        visited.resize(N, vector<int>(M));
    }

    void progress()
    {
        // 일단 visited가 있으면 편리할 것 같아요.
        // 방문하지 않은 곳에 대해서 도착하는 지점까지 dfs를 돌려서,
        // 마지막에 도달했을 경우 (visited에 가로막히는) 그 부분을 res vector에 넣고 빠져나오면 되지 않을까요?
        // 현재 반복 횟수를 저장해 놓는다면 편할 것 같아요.
        // visited에 기록되어 있는게 현재 반복횟수라면? 새로운 safe zone 만들기.
        // visited에 기록되어 있는 것이 이전 반복 횟수라면? 기존 safe zone에 종속시키기.

        int visitedCount = 1;

        for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            // 방문한 적 없는 곳일 경우
            if (visited[i][j] == 0)
            {
                visited[i][j] = visitedCount;
                dfs(i, j, visitedCount++);
            }
        }

        cout << accCount;
    }

    void dfs(int y, int x, int visitCount)
    {
        // 인덱스 움직이기
        Move(y, x);

        // 이전에 방문한 적 없는 새로운 공간?
        if (visited[y][x] == 0)
        {
            visited[y][x] = visitCount;
            dfs(y, x, visitCount);
        }
        // 현재 dfs 순회 중 방문했던 visited라면?
        else if (visited[y][x] == visitCount)
        {
            ++accCount;
        }

        return;
    }

private:
    bool Move(int& y, int& x)
    {
        switch (grid[y][x])
        {
        case 'U':
            y -= 1;
            break;
        case 'D':
            y += 1;
            break;
        case 'L':
            x -= 1;
            break;
        case 'R':
            x += 1;
            break;
        }

        return y >= 0 && y < N && x >= 0 && x < M;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

