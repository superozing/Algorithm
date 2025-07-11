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

	vector<long long> dp(101);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i < dp.size(); ++i)
		dp[i] = dp[i - 1] + dp[i - 5];

	int T;
	cin >> T;

	int in;
	while (T--)
	{
		cin >> in;
		cout << dp[in] << endl;
	}

	return 0;
}
 