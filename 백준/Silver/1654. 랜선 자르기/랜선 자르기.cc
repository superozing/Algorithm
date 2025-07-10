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

	int K, N;
	cin >> K >> N;

	vector<long long> lanLength(K);
	long long maxLanLength = 0;

	for (long long& i : lanLength)
	{
		cin >> i;
		maxLanLength = max(maxLanLength, i);
	}

	long long l = 1, r = maxLanLength;

	while (l <= r)
	{
		long long cut = (l + r) / 2;

		int curLanCnt = 0;
		for (long long i : lanLength)
			curLanCnt += i / cut;

		//cout << "l: " << l << ", r: " << r << ", cut: " << cut << endl;
		//cout << "curLanCnt: " << curLanCnt << endl;

		if (curLanCnt < N)
			r = cut - 1;
		else
			l = cut + 1;
	}

	cout << r;

	return 0;
}
