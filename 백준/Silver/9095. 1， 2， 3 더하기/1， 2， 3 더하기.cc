#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> dp(11);
	dp[1] = 1; // 1
	dp[2] = 2; // 11 2
	dp[3] = 4; // 111 12 21 3

	for (int i = 4; i < dp.size(); ++i)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int in;
	while (N--)
	{
		cin >> in;
		cout << dp[in] << endl;
	}

	return 0;
}
 