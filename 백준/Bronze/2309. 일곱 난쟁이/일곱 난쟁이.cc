#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int sum = 0;
    vector<int> nums(9);

    for (int& i : nums)
    {
        cin >> i;
        sum += i;
    }

    sort(begin(nums), end(nums));

    int excess_sum = sum - 100;

    for (int i = 0; i < 9; ++i)
    {
        for (int j = i + 1; j < 9; ++j)
        {
            if (nums[i] + nums[j] == excess_sum)
            {
                for (int k = 0; k < 9; ++k)
                {
                    if (i == k || j == k)
                        continue;

                    cout << nums[k] << endl;
                }

                return 0;
            }
        }
    }

    return 0;
}