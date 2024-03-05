#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class BAEKJOON // 포도주 시식
{
public:
    int         N;      // 포도주 수
    vector<int> wine;   // 포도주 벡터
    vector<int> dp;     // dp[n] => wine[n]까지 마셨을 때 최대로 마실 수 있는 포도주의 양

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N;

    wine.resize(N + 1, 0);
    dp.resize(N + 1, 0);

    // 포도주 벡터 채우기
    for (int i = 1; i < wine.size(); ++i)
        cin >> wine[i];
}


void BAEKJOON::progress()
{
    // dp의 초기값 설정
    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    // 그러면 dp[3]은 무엇일까...?
    // dp[3] = (wine[1] + wine[2]) , (wine[1] + wine[3]) , (wine[2] + wine[3]) 중에 max

    // 그러면 dp[4]는 무엇일까...?
    // dp[4] = (wine[1] + wine[2] + wine[4]) 또는 (wine[1] + wine[3] + wine[4]) 또는 (wine[2] + wine[3]) 중에 max

    // 이걸 정리하면
    //      (wine[2] + wine[3]) => dp[3]에 포함되어 있는 3가지(wine[1] + wine[2],  wine[1] + wine[3],  wine[2] + wine[3]) 중 하나. 
    //              wine[1] + wine[2], wine[1] + wine[3]의 경우에는 무조건 wine[4]를 더한 값이 크기 때문에 
    //              이전 dp[3]의 값이 wine[2] + wine[3]이었을 경우가 클 때를 위해서 체크함.
    //              그래서 dp[3]으로 치환 가능
    //      (wine[1] + wine[2] + wine[4]) => dp[2]에 wine[4]를 더한 값. 
    //      (wine[1] + wine[3] + wine[4]) => dp[1]에 wine[3] + wine[4]를 더한 값. 
    // 
    //      
    // dp[4] = max( { dp[3], dp[2] + wine[4], dp[1] + wine[3] + wine[4] } ); 


    // 이걸 i로 바꾸면
    // dp[i] = max( { dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i] } );


    for (int i = 3; i < dp.size(); ++i)
    {
        dp[i] = max({ dp[i - 1]
                    , dp[i - 2] + wine[i]
                    , dp[i - 3] + wine[i - 1] + wine[i] });
    }

    cout << dp.back();
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}
