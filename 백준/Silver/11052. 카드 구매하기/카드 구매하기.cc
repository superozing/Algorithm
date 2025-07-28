#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

struct Pack
{
	int price, count;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<Pack> packs(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> packs[i].price;
		packs[i].count = i + 1;
	}

	vector<int> dp(N + 1);

	for (int i = 0; i < dp.size(); ++i)
	{
		// 현재 인덱스 - 카드 개수 => valid index ? dp[현재 인덱스] = max(dp[현재 인덱스], dp[현재 인덱스 - 카드 개수] + 카드 가격)
		for (Pack& cur : packs)
		{
			if (i - cur.count < 0)
				continue;

			dp[i] = max(dp[i], dp[i - cur.count] + cur.price);
		}
	}

	cout << dp.back();

	return 0;
}
