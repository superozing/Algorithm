#include <iostream>
#include <algorithm>
#include <cmath>

#define endl ('\n')

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    long long X, Y, Z;
    cin >> X >> Y;

    Z = Y * 100 / X;

    //cout << Z << endl;

    // 이분 탐색 같아요.
    // 범위를 0 ~ X + Y 까지 대강 잡고, 게임을 최소 몇 번 더 해야 하는 지 구하면 될 것 같아요.

    long long answer = -1;
    long long l = 0, r = X + Y;

    while (l <= r)
    {
        // m: 게임 횟수
        long long m = (l + r) / 2;

        // m 회 게임을 이겼을 때, Z가 변하는가?
        long long curZ = (Y + m) * 100 / (X + m);
        
        //cout << "l: " << l << ",r: " << r << endl;
        //cout << "m: " << m << ", curZ: " << curZ << endl;

        if (curZ > Z)
        {
            answer = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    cout << answer;

    return 0;
}
