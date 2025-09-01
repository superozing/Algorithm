#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> prevDp(N);
	vector<int> curDp(N);

	cin >> prevDp[0];

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j < i; ++j)
			cin >> curDp[j];

		curDp[0] += prevDp[0];

		for (int j = 1; j < i - 1; ++j)
			curDp[j] += max(prevDp[j - 1], prevDp[j]);

		curDp[i - 1] += prevDp[i - 2];

		swap(curDp, prevDp);
	}

	cout << *max_element(begin(prevDp), end(prevDp));

	return 0;
}
