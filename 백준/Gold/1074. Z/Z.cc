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
    int N, R, C;

public:

    void input()
    {
        cin >> N >> R >> C;
    }

    void progress()
    {
        /*
        0  1  4  5  
        2  3  6  7  
        8  9  12 13
        10 11 14 15
        */

        // 사분면을 결정해요.
        // 어떻게 하는 것이 좋을까요?????

        // n = 2의 경우, 2의 제곱 => 4
        // 4를 절반으로 나눈 2(편의상 m)를 기준으로 행과 열을 판단해요.
        // r, c 모두 m을 넘지 못한다면    -> 0 번째(좌상
        // c만 넘긴다면                  -> 첫 번째(우상)
        // r만 넘긴다면                  -> 두 번째(좌하)
        // r, c 모두 m을 넘지 못한다면    -> 세 번째(우하)

        // 그러면 0, 1, 2, 3의 시작점을 알아야 해요.
        // 0: 0  (m^2) * 0
        // 1: 4  (m^2) * 1
        // 2: 8  (m^2) * 2
        // 3: 12 (m^2) * 3
        // 각각 경우에 맞게 answer에 누적해보아요.
        // 이후 n을 한 단계 내려 계산하기 위해 r,c중 m 넘을 경우 m을 빼요.


        // n = 1의 경우까지 더해주고, 결과를 계산해요.

        int answer = 0;

        while (N)
        {
            int m = pow(2, N) / 2;
            int mul = 0;

            if (C >= m)
                mul += 1;
            if (R >= m)
                mul += 2;

            R %= m;
            C %= m;
            answer += mul * m * m;
            --N;
        }

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

