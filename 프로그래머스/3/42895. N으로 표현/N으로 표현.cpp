#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int g_number = 0;

bool isAnswer(int cur)
{
    return g_number == cur;
}

int solution(int N, int number)
{
    g_number = number;
    // 5를 1번 사용했을 경우의 수
    // 5
    
    // 2번 사용한 경우의 수
    // 55 (5 에 5 붙이기) - 이건 조금 따로 봐야겠다.
    // 10: 5 + 5 (5에 5 더하기)
    // 0: 5 - 5 (5에 5 빼기)
    // 25: 5 * 5 (5에 5 곱하기)
    // 1: 5 / 5(5에 5 나누기)
    
    // 3번 사용한 경우의 수
    // 555 - 55에 5 붙이기. 딱 55 상태만 가능한 ㅇㅇ.
    // () + 5
    // () - 5, 5 - ()
    // () * 5
    // () / 5, 5 / ()
    
    // 이렇게 해서 연산의 결과가 number가 나올 때 까지 찾으면 될 듯.
    
    vector<set<int>> dp(9);
    
    if (N == number)
        return 1;
    
    dp[1].insert(N);
    if (isAnswer(N + N))
        return 2;
    else
        dp[2].insert(N + N);
    if (isAnswer(N - N))
        return 2;
    else
        dp[2].insert(N - N);
    if (isAnswer(N * N))
        return 2;
    else
        dp[2].insert(N * N);
    if (isAnswer(N / N))
        return 2;
    else
        dp[2].insert(N / N);
    if (isAnswer(N * 10 + N))
        return 2;
    else
        dp[2].insert(N * 10 + N);
    
    for (int i = 3; i < dp.size(); ++i)
    {
        // 반복되는 숫자 처리
        //cout << endl << "num count: " << i << endl;
        int continuous = N;
        for (int j = 0; j < i - 1; ++j)
            continuous = continuous * 10 + N;
        dp[i].insert(continuous);
        // cout << endl << "continuous: " << continuous << endl;
        
        for (int l = 1; l < i - 1; ++l)
        {
            int r = i - l;
            for (int left : dp[l])
            for (int right : dp[r])
            {
                if (right == 0 || left == 0)
                    continue;
                
                //cout << "l: " << left << "\t" << "r: " << right << endl;
                if (isAnswer(left + right))
                    return i;
                else 
                    dp[i].insert(left + right);
                
                if (isAnswer(left - right))
                    return i;
                else 
                    dp[i].insert(left - right);
                
                if (isAnswer(left - right))
                    return i;
                else 
                    dp[i].insert(left - right);
                
                if (isAnswer(right - left))
                    return i;
                else 
                    dp[i].insert(right - left);
                
                if (isAnswer(right * left))
                    return i;
                else 
                    dp[i].insert(right * left);
                
                if (isAnswer(right / left))
                    return i;
                else 
                    dp[i].insert(right / left);
                
                if (isAnswer(left / right))
                    return i;
                else 
                    dp[i].insert(left / right);
            }
        }

    }
    
    
    return -1;
}




















