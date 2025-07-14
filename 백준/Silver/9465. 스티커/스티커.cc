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

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		vector<vector<int>> grid(2, vector<int>(N));
		vector<vector<int>> dp(2, vector<int>(N));

		for (int i = 0; i < grid[0].size(); ++i)
			cin >> grid[0][i];
		for (int i = 0; i < grid[1].size(); ++i)
			cin >> grid[1][i];

		// 다른 줄 - 1의 dp 값을 가져오면 되지 않을까?
		dp[0][0] = grid[0][0];
		dp[1][0] = grid[1][0];

		for (int i = 1; i < grid[0].size(); ++i)
		{
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + grid[0][i]);
			dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + grid[1][i]);
		}

		cout << max(dp[0].back(), dp[1].back()) << endl;
	}
	
	return 0;
}
 