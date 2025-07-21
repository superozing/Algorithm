#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<vector<long long>> v(10, vector<long long>(N));

	for (int digit = 1; digit < 10; ++digit)
		v[digit][0] = 1;

	for (int i = 1; i < N; ++i)
	for (int digit = 0; digit < 10; ++digit)
	{
		if (digit == 0)
			v[1][i] = (v[1][i] + v[digit][i - 1]) % 1000000000;
		else if (digit == 9)
			v[8][i] = (v[8][i] + v[digit][i - 1]) % 1000000000;
		else
		{
			v[digit - 1][i] = (v[digit - 1][i] + v[digit][i - 1]) % 1000000000;
			v[digit + 1][i] = (v[digit + 1][i] + v[digit][i - 1]) % 1000000000;
		}
	}

	int answer = 0;
	for (int digit = 0; digit < 10; ++digit)
	{
		answer += v[digit].back();
		answer %= 1000000000;
	}

	cout << answer;

	return 0;
}
