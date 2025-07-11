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

	vector<int> stair(N);
	vector<int> dp(N);
	for (int& i : stair)
		cin >> i;

	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < dp.size(); ++i)
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], 
					dp[i - 2] + stair[i]);

	cout << dp.back();

	return 0;
}
 