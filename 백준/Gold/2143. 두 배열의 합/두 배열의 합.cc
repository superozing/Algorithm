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

    int T, N, M;
    
    cin >> T;
    
    cin >> N;
    vector<int> A(N);
    for (auto& i : A)
        cin >> i;
    
    cin >> M;
    vector<int> B(M);
    for (auto& i : B)
        cin >> i;

    vector<int> aSums;
    vector<int> bSums;

    for (int numCount = 1; numCount <= N; ++numCount)
    {
        int sum = 0;
        
        // 1. 슬라이딩 윈도우 채우기
        for (int i = 0; i < numCount; ++i)
            sum += A[i];

        aSums.push_back(sum);

        // 2. 순회하며 넣고 빼기
        for (int i = numCount; i < N; ++i)
        {
            sum -= A[i - numCount];
            sum += A[i];
            aSums.push_back(sum);
        }
    }

    for (int numCount = 1; numCount <= M; ++numCount)
    {
        int sum = 0;
        
        // 1. 슬라이딩 윈도우 채우기
        for (int i = 0; i < numCount; ++i)
            sum += B[i];

        bSums.push_back(sum);

        // 2. 순회하며 넣고 빼기
        for (int i = numCount; i < M; ++i)
        {
            sum -= B[i - numCount];
            sum += B[i];
            bSums.push_back(sum);
        }
    }

    if (aSums.size() > bSums.size())
        swap(aSums, bSums);

    sort(bSums.begin(), bSums.end());

    long long answer = 0;

    for (int i = 0; i < aSums.size(); ++i)
        answer += (upper_bound(bSums.begin(), bSums.end(), T - aSums[i]) - bSums.begin()) - (lower_bound(bSums.begin(), bSums.end(), T - aSums[i]) - bSums.begin());

    cout << answer;

    return 0;
}
