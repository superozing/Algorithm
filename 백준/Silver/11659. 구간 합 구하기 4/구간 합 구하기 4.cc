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
	
	int N, M;
	cin >> N >> M;

	vector<int> dp(N);

	cin >> dp[0];

	for (int i = 1; i < N; ++i)
	{
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	int s, e;
	while (M--)
	{
		cin >> s >> e;
		cout << dp[e - 1] - (s == 1 ? 0 : dp[s - 2]) << endl;
	}

	return 0;
}
 