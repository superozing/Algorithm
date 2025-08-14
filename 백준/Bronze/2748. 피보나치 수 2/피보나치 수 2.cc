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

	vector<long long> dp(N + 1);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < dp.size(); ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp.back();

	return 0;
}
