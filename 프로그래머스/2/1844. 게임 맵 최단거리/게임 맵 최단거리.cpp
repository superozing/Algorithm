#include <vector>
#include <queue>
using namespace std;

struct pos
{
    int y, x, c;
};

int solution(vector<vector<int>> maps)
{
    int dy[4] {1, 0, -1, 0};
    int dx[4] {0, 1, 0, -1};
    queue<pos> q;
        
    q.push({0, 0, 1});
    maps[0][0] = 0;
    
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();
        
        ++cur.c;
        
        for (int i = 0; i < 4; ++i)
        {
            pos next = cur;
            next.y += dy[i];
            next.x += dx[i];
            
            if (next.x >= 0 && next.x < maps[0].size() && 
               next.y >= 0 && next.y < maps.size() &&
               maps[next.y][next.x])
            {
                if (next.y == maps.size() - 1 &&
                    next.x == maps[0].size() - 1)
                    return next.c;
                
                maps[next.y][next.x] = 0;
                q.push(next);
            }
        }
    }
    
    return -1;
}