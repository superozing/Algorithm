#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct pos
{
    int y, x;
};

vector<int> xCnt;

int dy[4]{1, 0, -1, 0};
int dx[4]{0, 1, 0, -1};

void bfs(pos start, vector<vector<int>>& land)
{
    vector<bool> visitedX(static_cast<int>(land[0].size()), false);
    
    int acc = 1;
    queue<pos> q;
    q.push(start);
    land[start.y][start.x] = 0;
    visitedX[start.x] = true;
    
    while (!q.empty())
    {
        pos c = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            pos n = c;
            n.y += dy[i];
            n.x += dx[i];
            
            if (n.y >= 0 && n.y < land.size() &&
                n.x >= 0 && n.x < land[0].size() &&
                land[n.y][n.x] == 1)
            {
                land[n.y][n.x] = 0;
                visitedX[n.x] = true;
                ++acc;
                q.push(n);
            }
        }
    }
    
    for (int i = 0; i < visitedX.size(); ++i)
    {
        if (visitedX[i] == true)
            xCnt[i] += acc;
    }
}

int solution(vector<vector<int>> land) 
{
    xCnt.resize(static_cast<int>(land[0].size()));
    
    for (int y = 0; y < land.size(); ++y)
    for (int x = 0; x < land[0].size(); ++x)
    {
        if (land[y][x] == 1)
            bfs({y, x}, land);
    }
    
    return *max_element(begin(xCnt), end(xCnt));
}