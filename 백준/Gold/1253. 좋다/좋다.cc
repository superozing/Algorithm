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

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int& i : nums)
        cin >> i;

    sort(nums.begin(), nums.end());

    int answer = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int cur = nums[i];
        int l = 0;
        int r = N - 1;

        while (l < r)
        {
            if (r == i)
            {
                --r;
                continue;
            }
            if (l == i)
            {
                ++l;
                continue;
            }

            int sum = nums[l] + nums[r];

            if (sum == cur)
            {
                ++answer;
                break;
            }
            else if (sum > cur)
                --r;
            else
                ++l;
        }
    }

    cout << answer;

    return 0;
}
