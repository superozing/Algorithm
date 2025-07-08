#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int ans = 0;

	int N, M;
	cin >> N >> M;

	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	for (int i = 0;		i < v.size(); ++i)
	for (int j = i + 1; j < v.size(); ++j)
	for (int k = j + 1; k < v.size(); ++k)
	{
		int cur = v[i] + v[j] + v[k];

		if (cur <= M)
			ans = max(cur, ans);
	}

	cout << ans;

	return 0;
}