///////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cmath>

using namespace std;

#define endl ("\n")

class Boj
{
private:
    int N; // 표의 크기
    int M; // 합을 구해야 하는 횟수

    vector<vector<int>> grid;

public:

    void input()
    {
        cin >> N >> M;

        grid.resize(N, vector<int>(N));

        for (auto& line : grid)
        {
            int acc = 0;
            for (int& i : line)
            {
                cin >> i;
                i += acc;
                acc = i;
            }
        }

    }

    void progress()
    {
        // 억...어어!!!!!!!!!!!!!!
        // 어어어!!!!!!

        while (M--)
        {
            // 1   2   1   2
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int answer = 0;

            for (int i = x1 - 1; i < x2; ++i)
                answer += grid[i][y2 - 1] - (y1 - 2 == -1 ? 0 : grid[i][y1 - 2]);

            cout << answer << endl;
        }
    }

private:

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

