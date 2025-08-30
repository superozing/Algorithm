#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	// 타일: 00, 1

	// N = 1 일 경우 1
	// N = 2 일 경우 11, 00
	// N = 3 일 경우 111, 100, 001
	// N = 4 일 경우 1111, 1100, 1001, 0011, 0000
	// dp[i] = dp[i - 1] + dp[i - 2]

	if (N <= 2)
	{
		if (N == 1)
			cout << 1;
		if (N == 2)
			cout << 2;

		return 0;
	}
	
	int dp[3] { 1, 2, 0 };

	for (int i = 3; i <= N; ++i)
	{
		dp[2] = (dp[0] + dp[1]) % 15746;
		
		dp[0] = dp[1];
		dp[1] = dp[2];
	}

	cout << dp[1];

	return 0;
}
