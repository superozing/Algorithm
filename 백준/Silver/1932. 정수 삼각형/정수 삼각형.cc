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
        grid.resize(N + 1);
    }

    void progress()
    {
        int in;
        cin >> in;
        grid[1].push_back(in);

        for (int i = 2; i <= N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                cin >> in; 
                grid[i].push_back(in);
                
                if (j == 0)
                    grid[i][0] += grid[i - 1][0];
                else if (j == i - 1)
                    grid[i][j] += grid[i - 1][j - 1];
                else
                    grid[i][j] += max(grid[i - 1][j - 1], grid[i - 1][j]);
            }
        }

        cout << *max_element(begin(grid.back()), end(grid.back()));
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

