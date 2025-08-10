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

	int N, K; // 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수 구하기
	cin >> N >> K;

	// dp[i][j] => i개의 정수를 더해서 j을 만들 수 있는 경우의 수
	// 1차원 두 개로 최적화 할 수도 있겠어요.
	vector<vector<int>> dp(K + 1, vector<int>(N + 1));
	
	// dp[1][j]은 숫자 한 개를 사용해 만들 수 있다. (경우의 수 한 가지)
	for (int i = 0; i < N + 1; ++i)
		dp[1][i] = 1;

	// dp[2][j] => 2개의 정수를 더해서 j을 만들 수 있는 경우의 수
	// dp[2][0] => 0+0
	// dp[2][1] => 0+1, 1+0
	// dp[2][2] => 0+2, 1+1, 2+0

	// dp[2][0] += dp[1][0]
	// dp[2][1] += dp[1][0] + dp[1][1]
	// dp[2][2] += dp[1][0] + dp[1][1] + dp[1][2]

	// dp[i][j] += dp[i - 1][0] + ... + dp[i - 1][j]

	for (int i = 1; i < dp.size(); ++i)
	for (int j = 0; j < dp[0].size(); ++j)
	for (int k = 0; k <= j; ++k)
		dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1'000'000'000;

	cout << dp.back().back();

	return 0;
}
