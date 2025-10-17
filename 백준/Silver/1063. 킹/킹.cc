#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

struct Pos
{
    int y, x;
};

int dy[8]{ 0, 0, -1, 1, 1, 1, -1, -1 };
int dx[8]{ 1, -1, 0, 0, 1, -1, 1, -1 };

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> grid(8, vector<int>(8));

    // 8방향 탐색 돌려야 해요

    string in;
    cin >> in;
    Pos king{in[1] - '1', in[0] - 'A'};
    cin >> in;
    Pos stone{ in[1] - '1', in[0] - 'A' };
    
    int N;
    cin >> N;

    while (N--)
    {
        int curIdx;

        cin >> in;
        if (in == "R")
            curIdx = 0;
        else if (in == "L")
            curIdx = 1;
        else if (in == "B")
            curIdx = 2;
        else if (in == "T")
            curIdx = 3;
        else if (in == "RT")
            curIdx = 4;
        else if (in == "LT")
            curIdx = 5;
        else if (in == "RB")
            curIdx = 6;
        else
            curIdx = 7;

        auto nextKing = king;
        nextKing.y += dy[curIdx];
        nextKing.x += dx[curIdx];

        if (nextKing.y >= 0 && nextKing.y < 8 && nextKing.x >= 0 && nextKing.x < 8)
        {
            if (nextKing.y == stone.y && nextKing.x == stone.x)
            {
                auto nextStone = stone;
                nextStone.y += dy[curIdx];
                nextStone.x += dx[curIdx];

                if (nextStone.y >= 0 && nextStone.y < 8 && nextStone.x >= 0 && nextStone.x < 8)
                {
                    stone = nextStone;
                    king = nextKing;
                }
            }
            else
                king = nextKing;
        }
    }

    cout << char(king.x + 'A') << char(king.y + '1') << endl;
    cout << char(stone.x + 'A') << char(stone.y + '1') << endl;

    return 0;
}
