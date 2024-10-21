////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;


class Boj
{
private:
    int N; // 정수 개수
    vector<int> nums; // n개의 정수

public:
    void input()
    {
        cin >> N;

        nums.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> nums[i];
    }

    void progress()
    {
        // 연속된 배열의 요소 중 가장 큰 값.
        vector<int> dp(N);

        /*
            10 -4 3 1 5 6 -35 12 21 -1
            1. 10
            2. 10과 10 + -4 를 비교해서 10이 더 크기 때문에 10만 기록한 상태, 이전 연산 결과인 10을 max로 두기
            3. max인 10과, 10 + -4 + 3을 비교해서 큰 값을 골라 넣기
                만약 second 값이 0보다 작다면 (예를 들어 10 + -12같은 경우.....) 3으로 cur을 바꿔줘야 해요. 
            4. 10과 10 + -4 + 3 + 1을 비교
            5. 10과 10 + -4 + 3 + 1 + 5를 비교

            경우의 수가
            지속한 값에 더한 값이 큰가
            최대 값이 큰가
            새로 만드는 값이 큰가
            이 세 개를 게속 기록해주어야 할 것 같은데
        */

        int maxValue = 0;

        maxValue = dp[0] = nums[0];

        for (int i = 1; i < N; ++i)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);

            maxValue = max(dp[i], maxValue);
        }

        cout << maxValue;
    }

};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}
