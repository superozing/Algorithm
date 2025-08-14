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

	// 이친수는 0으로 시작하지 않는다.
	// 이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.

	// [2][n] 크기의 dp를 만들어서 해결해보아요.
	// [0][i] => [0][i + 1], [1][i + 1]로 이어질 수 있다.
	// [1][i] => [0][i + 1] 로만 이어질 수 있다 (1은 두 번 연속으로 나타나지 않음)

	int N;
	cin >> N;

	vector<vector<long long>> dp(2, vector<long long>(N));

	dp[1][0] = 1;

	for (int i = 1; i < dp[0].size(); ++i)
	{
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}

	cout << dp[0].back() + dp[1].back();

	return 0;
}
