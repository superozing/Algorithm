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

	vector<pair<int, int>> dp(41);
	dp[0] = {1, 0};
	dp[1] = {0, 1};

	for (int i = 2; i < dp.size(); ++i)
		dp[i] = { dp[i - 2].first + dp[i - 1].first, dp[i - 2].second + dp[i - 1].second };

	int T;
	cin >> T;

	int N;
	while (T--)
	{
		cin >> N;
		cout << dp[N].first << ' ' << dp[N].second << endl;
	}

	return 0;
}
