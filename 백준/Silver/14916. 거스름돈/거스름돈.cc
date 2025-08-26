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
	
	if (N <= 5)
	{
		if (N == 2 || N == 5)
			cout << 1;
		else if (N == 4)
			cout << 2;
		else
			cout << -1;
		return 0;
	}

	vector<int> dp(N + 1, 1e9);

	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;

	for (int i = 6; i < N + 1; ++i)
		dp[i] = min(dp[i - 5], dp[i - 2]) + 1;

	cout << (1e9 <= dp.back() ? -1 : dp.back());

	return 0;
}
