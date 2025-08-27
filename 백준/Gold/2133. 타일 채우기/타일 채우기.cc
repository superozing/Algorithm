#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	if (N <= 4)
	{
		if (N == 2)
			cout << 3;
		else if (N == 4)
			cout << 11;
		else
			cout << 0;

		return 0;
	}

	vector<int> dp(N + 1);

	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;

	for (int i = 6; i < dp.size(); i += 2)
	{
		dp[i] = dp[i - 2] * 3;

		for (int j = 4; j <= i; j += 2)
			dp[i] += dp[i - j] * 2;
	}

	cout << dp.back();

	return 0;
}
