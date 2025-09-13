#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

#define endl ('\n')

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 먼저, 홍준이는 자연수 N개를 칠판에 적는다. 그 다음, 명우에게 질문을 총 M번 한다.
	// S번째 수부터 E번째 까지 수가 팰린드롬을 이루는지를 물어보며, 
	// 명우는 각 질문에 대해 팰린드롬이다 또는 아니다를 말해야 한다.

	int N;
	cin >> N;

	vector<int> nums(N);
	for (auto& num : nums)
		cin >> num;

	vector<vector<bool>> dp(N, vector<bool>(N));

	// dp[i][j] = i 부터 j 까지 수가 팰린드롬인가?

	// dp[i][i] = 반드시 팰린드롬
	for (int i = 0; i < N; ++i)
		dp[i][i] = true;


	// dp[i][j] = dp[i + 1][j - 1]과 nums[i], nums[j] 비교
	for (int l = 1; l < N; ++l)
	for (int s = 0; s < N - l; ++s)
	{
		int e = s + l;

		if (l == 1 || dp[s + 1][e - 1])
			dp[s][e] = nums[s] == nums[e];
	}

	int M;
	cin >> M;

	while (M--)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s - 1][e - 1] << endl;
	}

	return 0;
}

