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
    int N;
    vector<vector<int>> grid;

public:

    void input()
    {
        cin >> N;
        grid.resize(N, vector<int>(N));

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> grid[i][j];
    }

    void progress()
    {
        for (int n = 0; n < N; ++n)
        for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (grid[i][j] == 0)
                grid[i][j] = int(grid[i][j] || (grid[i][n] && grid[n][j]));
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout << grid[i][j] << " ";

            cout << endl;
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

