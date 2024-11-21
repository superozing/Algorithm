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
    int white = 0, blue = 0;
    vector<vector<int>> grid;

public:

    void input()
    {
        cin >> N;

        grid.resize(N, vector<int>(N));

        for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
           cin >>grid[i][j];
    }

    void progress()
    {
        divAndCon(0, 0, N);

        cout << white << endl << blue;
    }

private:

    void divAndCon(int l, int t, int n)
    {
        int firstColor = grid[l][t];
        bool divide = false;

        for (int i = l; i < l + n; ++i)
        for (int j = t; j < t + n; ++j)
        {
            if (firstColor != grid[i][j])
            {
                divide = true;
                break;
            }
        }

        if (divide)
        {
            int len = n / 2;

            divAndCon(l,         t,          len);
            divAndCon(l + len,   t,          len);
            divAndCon(l,         t + len,    len);
            divAndCon(l + len,   t + len,    len);
        }
        else
            firstColor ? ++blue : ++white;

        return;
    }

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

