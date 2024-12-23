#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int y, x;
};

int dy[4]{0, 1, 0, -1};
int dx[4]{-1, 0, 1, 0};

int solution(vector<vector<string>> board, int h, int w) 
{
    int answer = 0;
    
    string firstColor = board[h][w];
        
    pos c {h, w};
    
    for (int i = 0; i < 4; ++i)
    {
        pos next = c;
        next.y += dy[i];
        next.x += dx[i];

        if (next.y >= 0 && next.y < board.size() &&
            next.x >= 0 && next.x < board[0].size() &&
            board[next.y][next.x] == firstColor)
        {
            ++answer;
        }
    }

    return answer;
}