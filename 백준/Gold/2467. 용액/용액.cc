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
	vector<int> sols(N);
	for (int& i : sols)
		cin >> i;

	sort(begin(sols), end(sols));

	int answer = 1e9 * 2 + 1;
	int ansL = 0;
	int ansR = 0;


	int l = 0;
	int r = sols.size() - 1;

	while (l < r)
	{
		int cur = sols[l] + sols[r];
		
		if (abs(answer) > abs(cur))
		{
			answer = cur;
			ansL = l;
			ansR = r;
		}

		if (cur > 0)
			r--;
		else if (cur < 0)
			l++;
		else
			break;
	}

	cout << sols[ansL] << ' ' << sols[ansR];

	return 0;
}
