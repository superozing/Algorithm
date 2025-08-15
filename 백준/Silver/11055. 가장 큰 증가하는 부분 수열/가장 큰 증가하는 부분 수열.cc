#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것

	int N;
	cin >> N;

	vector<int> nums(N);
	for (int& i : nums)
		cin >> i;

	vector<int> dp(nums);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] <= nums[j])
				continue;

			dp[i] = max(dp[i], dp[j] + nums[i]);
		}
	}

	cout << *max_element(begin(dp), end(dp));

	return 0;
}
