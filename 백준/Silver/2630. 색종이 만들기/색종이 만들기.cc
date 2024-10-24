#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Boj
{
private:
    int N; // 한 변의 길이
    vector<vector<int>> paper; // 색종이

    int whitePaper = 0;
    int bluePaper = 0;

public:
    void input()
    {
        cin >> N;
        paper.resize(N, vector<int>(N));

        for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> paper[i][j];

    }

    void progress()
    {
        cut(0, N, 0, N);

        cout << whitePaper << endl << bluePaper;
    }

    void cut(int l, int r, int t, int b)
    {

        // 가장 첫 부분을 현재 색상으로 잡아요.
        int curColor = paper[l][t];
        int cutFlag = false;


        for (int i = l; i < r; ++i)
        {
            for (int j = t; j < b; ++j)
            {
                if (paper[i][j] != curColor)
                {
                    cutFlag = true;
                    break;
                }
            }
            if (cutFlag)
                break;
        }

        if (cutFlag)
        {
            cut(l, (l + r) / 2,      t, (t + b) / 2); // 좌상단
            cut((l + r) / 2,    r,          t, (t + b) / 2); // 우상단
            cut(l, (l + r) / 2,      (t + b) / 2,    b); // 좌하단
            cut((l + r) / 2,    r,          (t + b) / 2,    b); // 우하단
        }
        else
            curColor ? ++bluePaper : ++whitePaper;

        return;
    }

private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}

