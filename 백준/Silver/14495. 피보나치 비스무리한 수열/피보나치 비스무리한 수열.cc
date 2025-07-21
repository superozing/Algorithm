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

	if (N <= 3)
	{
		cout << 1;
		return 0;
	}

	vector<long long> dp(N + 1);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i < N + 1; ++i)
		dp[i] = dp[i - 1] + dp[i - 3];

	cout << dp[N];

	return 0;
}
