#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define endl ('\n')

using namespace std;

int dy[4]{ 1, 0, -1, 0 };
int dx[4]{ 0, 1, 0, -1 };

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int R, C, N;
    cin >> R >> C >> N;

    vector<string> grid(R);
    for (string& s : grid)
        cin >> s;

    vector<vector<int>> bombs(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
        bombs[i][j] = grid[i][j] == 'O' ? 2 : 0;

    N--;

    while (N--)
    {
        vector<pair<int, int>> explosion;

        for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (!bombs[i][j])
                bombs[i][j] = 3;
            else
                bombs[i][j]--;
        }

        if (N == 0)
            break;
        
        N--;

        for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            bombs[i][j]--;

            if (!bombs[i][j])
                explosion.push_back({ i, j });
        }

        for (auto& pii : explosion)
        {
            for (int i = 0; i < 4; ++i)
            {
                auto next = pii;
                next.first += dy[i];
                next.second += dx[i];

                if (next.first >= 0 && next.first < R && next.second >= 0 && next.second < C)
                    bombs[next.first][next.second] = 0;
            }
        }
    }

    for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
        grid[i][j] = bombs[i][j] ? 'O' : '.';

    for (string& s : grid)
        cout << s << endl;

    return 0;
}
