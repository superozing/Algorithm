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

enum color
{
    r, g, b,
};

class Boj
{
private:
    int N; // 집의 수

    vector<vector<int>> RGB; // 비용

public:

    void input()
    {
        cin >> N;
        RGB.resize(N + 1, vector<int>(3));

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < 3; ++j)
                cin >> RGB[i][j];
        }
    }

    void progress()
    {
        /*
        1번 집의 색은 2번 집의 색과 같지 않아야 한다.
        N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
        i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
        */

        // RGRGRGRG 이런 식으로 해도 된다..
        // R -> G 또는 B로 나아갈 수 있다.
        // R 입장에서는 G와 B 중 최소로 나아가야 한다.

        for (int i = 2; i <= N; ++i)
        {
            RGB[i][r] += min(RGB[i - 1][g], RGB[i - 1][b]);
            RGB[i][g] += min(RGB[i - 1][r], RGB[i - 1][b]);
            RGB[i][b] += min(RGB[i - 1][r], RGB[i - 1][g]);
        }

        int answer = 1e9;

        for (int it : RGB[N])
            answer = min(answer, it);

        cout << answer;
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

