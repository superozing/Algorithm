#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class BAEKJOON // 호텔
{
public:
    int C; // 적어도 늘려야 할 고객 수
    int N; // 홍보할 수 있는 도시의 개수
    vector<ii> city; // pair<홍보 비용, 고객 수>
    vector<int> dp;  // 돈을 i 만큼 사용할 때 최대 고객 수 

public:
    BAEKJOON() { cout << progress() << endl; }
    void init();
    int progress();
};

void BAEKJOON::init()
{
    cin >> C;
    cin >> N;

    city.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> city[i].first >> city[i].second;

    dp.resize(100001); // N 최대값 1000 * C 최대값 100
}

int BAEKJOON::progress()
{
    init();

    int cost = 0;
    int man = 0;

    // max(dp[i], dp[i - cost] + man)
    // 
    //  i(현재 가격) 에서 cost(홍보 비용) 만큼 뺀 곳에서 
    //  홍보를 진행했을 때의 결과가 계산된다.
    //  
    //  dp[i]에는 결국 i만큼의 비용을 사용했을 때 
    //  i - cost 에서 홍보를 진행한 것과, 진행하지 않은 것 
    //  둘 중에 무엇이 이득인지 저장된다.
    //  이 것을 모든 도시의 경우에서 체크해가면서 dp를 채워나간다.

    for (auto& it : city)
    {
        cost = it.first; // 홍보에 사용되는 비용
        man = it.second; // 홍보로 얻는 사람 수

        for (int i = 1; i <= 100000; ++i)
            if (i - cost >= 0)
                dp[i] = max(dp[i], dp[i - cost] + man);

    }


    for (int i = 1; i <= 100000; ++i)
        if (dp[i] >= C)
            return i;

    return 0;
}

int main()
{
    BAEKJOON b;
    return 0;
}

