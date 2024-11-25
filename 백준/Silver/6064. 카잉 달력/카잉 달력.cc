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
    int T;
    int N, M;
    int X, Y;

public:

    void input()
    {
        cin >> T;
    }

    void progress()
    {
        while (T--)
        {
            cin >> N >> M >> X >> Y;

            // n이 x일 때, m이 y인 때를 찾아야 한다.
            // n이 x인 경우: 0n + x, 1n + x, 2n + x, 3n + x... 편의상 nx
            // nx를 M으로 나눈 나머지가 Y 여야 해요.
            int nx = X;
            int maxYear = N * M / gcd(N, M);

            if (M == Y)
                Y = 0;

            while (nx <= maxYear && nx % M != Y)
            {
                nx += N;
            }

            if (nx > maxYear)
                cout << -1 << endl;
            else
                cout << nx << endl;
        }
    }

private:

    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int c = a % b;
            a = b;
            b = c;
        }

        return a;
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

