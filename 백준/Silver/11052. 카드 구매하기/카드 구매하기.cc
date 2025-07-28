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

	vector<int> packs(N);
	for (int& i : packs)
		cin >> i;

	vector<int> dp(N + 1);

	for (int i = 1; i < dp.size(); ++i)
	{
		// 현재 인덱스 - 카드 개수 => valid index ? dp[현재 인덱스] = max(dp[현재 인덱스], dp[현재 인덱스 - 카드 개수] + 카드 가격)
		for (int j = 0; j < packs.size(); ++j)
		{
			if (i < j + 1)
				continue;

			dp[i] = max(dp[i], dp[i - (j + 1)] + packs[j]);
		}
	}

	cout << dp.back();

	return 0;
}
