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

	// dp[i] = i를 만들기 위한 최소 항 개수
	vector<int> dp(N + 1, 4);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i < dp.size(); ++i)
	{
		int sq = sqrt(i);
		if (sq * sq == i)
		{
			dp[i] = 1;
			continue;
		}

		for (int j = 1; j * j < i; ++j)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}

	cout << dp.back();

	return 0;
}
