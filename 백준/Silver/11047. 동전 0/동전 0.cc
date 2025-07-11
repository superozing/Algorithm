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

	int N, K;
	cin >> N >> K;

	vector<int> v(N);

	for (int i = N - 1; i >= 0; --i)
		cin >> v[i];

	int answer = 0;

	for (int i = 0; K != 0; ++i)
	{
		answer += K / v[i];
		K %= v[i];
	}

	cout << answer;

	return 0;
}
