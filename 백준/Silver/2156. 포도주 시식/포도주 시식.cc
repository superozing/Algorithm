#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	/*
	포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 
	마신 후에는 원래 위치에 다시 놓아야 한다.
	연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
	*/

	// 계단 오르기가 생각나는 문제에요.

	int N;
	cin >> N;

	vector<int> wines(N);
	for (auto& i : wines)
		cin >> i;

	// dp[i] => i 번째까지 규칙에 따라 마셨을 때 마실 수 있는 최대 포도주 양

	switch (N)
	{
	case 1:
		cout << wines[0];
		return 0;

	case 2:
		cout << wines[0] + wines[1];
		return 0;

	case 3:
		cout << max(wines[0] + wines[1], max(wines[0], wines[1]) + wines[2]);
		return 0;
	}

	int answer = 0;
	vector<int> dp(N);
	dp[0] = wines[0];
	dp[1] = wines[0] + wines[1];
	dp[2] = max(dp[1], max(wines[0], wines[1]) + wines[2]);

	for (int i = 3; i < N; ++i)
	{
		// 1. i - 3, i - 1, i 를 마시기
		// 2. i - 2, i 를 마시기
		// 3. i를 안마시기
		dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3] + wines[i - 1]) + wines[i]);
	}

	cout << *max_element(begin(dp), end(dp));

	return 0;
}
