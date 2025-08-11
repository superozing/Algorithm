#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

struct Wire
{
	int s, d;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	
	vector<Wire> wires(N);
	for (auto& wire : wires)
	{
		cin >> wire.s;
		cin >> wire.d;
	}

	sort(begin(wires), end(wires), [](const Wire& a, const Wire& b) { return a.s < b.s; });

	vector<int> dp(N, 1);

	int answer = 0;

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < i; ++j)
		if (wires[i].d > wires[j].d)
			dp[i] = max(dp[i], dp[j] + 1);

	cout << N - *max_element(begin(dp), end(dp));

	return 0;
}
