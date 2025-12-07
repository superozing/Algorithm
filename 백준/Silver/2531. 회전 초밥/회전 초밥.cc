#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // 1. 벨트의 한 위치부터 k 개 연속 먹을 것
    // 2. 초밥 쿠폰에 적힌 초밥 하나를 추가로 무료 제공 ( 없으면 만들어서 제공 )

    // 가격 상관 없이 가장 많은 가짓수의 초밥 먹는 방법 구하기

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> belt(N);
    for (auto& sushi : belt)
        cin >> sushi;

    unordered_map<int, int> sushiType;
    
    int maxSushiTypeCount = 0;

    for (int i = 0; i < k; ++i)
        sushiType[belt[i]]++;

    maxSushiTypeCount = sushiType.size() + (int)(sushiType.find(c) == sushiType.end());

    for (int i = k; i < N + k; ++i)
    {
        int prevSushi = belt[(i - k) % N];
        int curSushi = belt[i % N];
        
        sushiType[curSushi]++;
        sushiType[prevSushi]--;

        if (sushiType[prevSushi] == 0)
            sushiType.erase(prevSushi);

        int curSushiTypeCount = sushiType.size() + (int)(sushiType.find(c) == sushiType.end());

        maxSushiTypeCount = max(maxSushiTypeCount, curSushiTypeCount);
    }

    cout << maxSushiTypeCount;

    return 0;
}
