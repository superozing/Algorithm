#include <vector>
#include <list>
using namespace std;

struct pos
{
    int y;
    int x;
    int cnt;
    pos() {}
    pos(int _y, int _x, int _c) : y(_y), x(_x), cnt(_c) {}
};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    // 0은 벽, 1은 지나갈 수 있는 공간.
    
    list<pos> q;
    int pX[4] {-1, 0, 1, 0};
    int pY[4] { 0, -1, 0, 1};
    
    q.push_back({0, 0, 1});
    maps[0][0] = false;
    // 원본 수정해도 될 것 같아요.
    
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop_front();
        
        cur.cnt += 1;
        
        for (int i  =0; i < 4; ++i)
        {
            pos pnew = cur;
            pnew.y += pY[i];
            pnew.x += pX[i];
            
            if (pnew.y < maps.size() && pnew.x < maps[0].size() &&
                pnew.y >= 0 && pnew.x >= 0 &&
                maps[pnew.y][pnew.x])
            {
                if (maps.size() - 1 == pnew.y && maps[0].size() - 1 == pnew.x)
                    return pnew.cnt;
                
                q.push_back(pnew);
                maps[pnew.y][pnew.x] = false;
            }
        }
        
    }
    
        
    
    
    
    
    
    
    return -1;
}