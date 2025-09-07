#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	 // 1~N 번 집

	// 빨 초 파로 칠
	
	/*
	1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다. (1번 집과 마지막 집의 색이 같지 않아야 한다는 조건이 추가되었네요.)
	N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
	i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.
	*/

	int N;
	cin >> N;

	vector<vector<int>> houses(N, vector<int>(3));
	for (auto& house : houses)
		for (auto& i : house)
			cin >> i;

	// 음...
	// 아마도 dp 를 총 3번 돌면 될 것 같아요.

	// 첫 집은 빨 색으로 시작하여 마지막 집은 초, 파로 도착하는 dp
	// 첫 집은 초 색으로 시작하여 마지막 집은 빨, 파로 도착하는 dp
	// 첫 집은 파 색으로 시작하여 마지막 집은 빨, 초로 도착하는 dp

	vector<vector<int>> dp(N, vector<int>(3));

	int answer = 1e9;

	// 빨강부터 시작
	dp[0] = houses[0];
	dp[0][1] = 1001;
	dp[0][2] = 1001;

	for (int i = 1; i < dp.size(); ++i)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + houses[i][2];
	}

	answer = min(answer, min(dp.back()[1], dp.back()[2]));

	// 초록부터 시작
	dp[0] = houses[0];
	dp[0][0] = 1001;
	dp[0][2] = 1001;

	for (int i = 1; i < dp.size(); ++i)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + houses[i][2];
	}

	answer = min(answer, min(dp.back()[0], dp.back()[2]));

	// 파랑부터 시작
	dp[0] = houses[0];
	dp[0][0] = 1001;
	dp[0][1] = 1001;

	for (int i = 1; i < dp.size(); ++i)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + houses[i][2];
	}

	answer = min(answer, min(dp.back()[0], dp.back()[1]));

	cout << answer;

	return 0;
}
