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

	vector<int> dp(N + 1);

	dp[1] = 1;
	dp[2] = 3;

	if (N <= 2)
	{
		cout << dp[N];
		return 0;
	}

	for (int i = 3; i < dp.size(); ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;


	cout << dp.back() % 10007;

	return 0;
}
 