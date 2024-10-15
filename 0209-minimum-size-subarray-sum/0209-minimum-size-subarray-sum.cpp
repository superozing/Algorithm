class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& n) 
    {
        int minLen = INT_MAX;
        // subarray 내부의 모든 요소를 더했을 때, target보다 큰,가장 짧은 길이를 가진 subarray
        // 슬라이딩 윈도우

        int l = 0;
        int r = 0;

        int sum = 0;

        while (r < n.size())
        {
            // 1. target을 넘지 않는 경우
            // target을 넘을 때 까지 ++r
            sum += n[r];
            ++r;
            // 2. target을 넘을 경우
            //cout << sum;
            while (sum >= target)
            {
                //cout << "(" << sum << ", "<< r - l << ")";
                // 가장 작은 길이 기록
                minLen = min(minLen, r - l);
                // target보다 작을 때 까지 ++l
                // 앞 쪽 데이터 제거
                sum -= n[l];
                ++l;
            }
            cout << endl;
        }
 
        return minLen == INT_MAX ? 0 : minLen;
    }
};