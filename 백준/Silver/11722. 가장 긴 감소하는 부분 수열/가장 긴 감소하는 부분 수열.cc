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

	int N;
	cin >> N;

	vector<int> nums(N);
	for (int& i : nums)
		cin >> i;

	vector<int> dp(N, 1); // 최소 길이로 초기화

	// dp[i] = nums[i]를 포함한 가장 긴 감소하는 부분 수열의 길이
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < i; ++j)
	{
		if (nums[i] < nums[j])
			dp[i] = max(dp[i], dp[j] + 1);
	}

	cout << *max_element(begin(dp), end(dp));

	return 0;
}
