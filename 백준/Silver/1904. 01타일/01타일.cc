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

	// N = 1일 때 1만 만들 수 있고, N = 2일 때는 00, 11을 만들 수 있다. (01, 10은 만들 수 없게 되었다.) 
	// 	또한 N = 4일 때는 0011, 0000, 1001, 1100, 1111 등 총 5개의 2진 수열을 만들 수 있다.

	int N;
	cin >> N;

	vector<int> dp(N + 1);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < dp.size(); ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;

	cout << dp.back();

	return 0;
}
