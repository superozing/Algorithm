#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) 
{
    long long answer = 0;
    
    sort(begin(times), end(times));
    // 시간을 이분 탐색 해봐요.
    // 각 시간마다 최대 몇 명을 심사할 수 있는지 계산해야 한다.
    
    long long l = 0;
    long long r = 1'000'000'000 * (long long)n;
    
    while (l <= r)
    {
        long long m = (l + r) / 2;
        //cout << "m: " << m << ", l: " << l << ", r: " << r << endl;
        
        long long cnt = 0;
        
        for (int time : times)
        {
            cnt += m / (long long)time;
            //cout << m / time << endl;            
        }
        
        //cout << "cnt: " << cnt << endl;
        if (cnt >= n)
            r = m - 1;
        else
            l = m + 1;
    }
    
    return l;
}