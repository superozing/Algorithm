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
    int N;

    vector<string> stars; // 공백인 부분만 true 처리하면 알아서 될 것 같아요.

public:
    void input()
    {
        cin >> N;
        stars.resize(N, string(N, '*'));
    }

    void progress()
    {
        star(0, 0, N);

        for (int i = 0; i < stars.size(); ++i)
        {
            printf(stars[i].c_str());
            printf("\n");
        }
    }

    void star(int l, int t, int length)
    {
        // 1. 일단 입력으로 들어온 부분 중, 가운데 [l + (length / 3)][t + (length / 3)]부분은 반드시 공백이다.
        int one_third = (length / 3);
        int two_third = one_third * 2;

        for (int i = l + one_third; i < l + two_third; ++i)
        for (int j = t + one_third; j < t + two_third; ++j)
            stars[i][j] = ' ';

        if (length == 3) // 더 분할할 수 없으면 반환
            return;

        // 2. 나머지 8방향에 star을 쏘아야 해요.
        star(l,             t,              one_third);
        star(l + one_third, t,              one_third);
        star(l + two_third, t,              one_third);

        star(l,             t + one_third,  one_third);
        // 가운데는 비워요.
        star(l + two_third, t + one_third,  one_third);
        
        star(l,             t + two_third,  one_third);
        star(l + one_third, t + two_third,  one_third);
        star(l + two_third, t + two_third,  one_third);
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

