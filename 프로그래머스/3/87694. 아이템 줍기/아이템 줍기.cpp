#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct pos
{
    int y, x, c;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) 
{
    // 외곽선을 탐색하기 위해서 grid의 크기를 두 배로 늘리면 된다.
    vector<vector<int>> grid(102, vector<int>(102));
    int dy[4] {0, 1, 0, -1};
    int dy2[8] {0, 1, 0, -1, -1, 1, -1, 1};
    int dx[4] {-1, 0, 1, 0};
    int dx2[8] {-1, 0, 1, 0, -1, -1, 1, 1};
    
    for (vector<int>& rect : rectangle)
    {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        
        for (int i = y1; i <= y2; ++i)
        for (int j = x1; j <= x2; ++j)
            grid[i][j] = 1;
    }

    // 빈 곳: 0
    // 직사각형: 1
    // visited: 2
    // 선물 위치: 3
    grid[itemY * 2][itemX * 2] = 3;
    
    // for (vector<int>& x : grid)
    // {
    //     for (int i : x)
    //         cout << i;
    //     cout << endl;
    // }
    
    
    // 외곽선: 현재 위치가 1이며 주변에 0이 한 개 이상 있는 경우 외곽선.
    
    queue<pos> q;
    q.push({characterY * 2, characterX * 2, 0});
    grid[characterY * 2][characterX * 2] = 2;
    
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();
        cur.c++;
        
        for (int i = 0; i < 4; ++i)
        {
            pos next = cur;
            next.y += dy[i];
            next.x += dx[i];
            
            if (next.y >= 0 && next.y < 102 &&
               next.x >= 0 && next.x < 102)
            {
                if (grid[next.y][next.x] == 3)
                    return next.c / 2;
                
                if (grid[next.y][next.x] != 1)
                    continue;
                
                for (int i = 0; i < 8; ++i)
                {
                    if (next.y + dy2[i] >= 0 && next.y + dy2[i] < 102 &&
                        next.x + dx2[i] >= 0 && next.x + dx2[i] < 102 &&
                        grid[next.y + dy2[i]][next.x + dx2[i]] == 0)
                    {
                        grid[next.y][next.x] = 2;
                        q.push(next);
                        break;
                    }                        
                }
            }
        }
    }
    
    return 0;
}












































