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

	vector<int> nums(N);
	for (int& i : nums)
		cin >> i;

	sort(begin(nums), end(nums));

	int minValue = 1e9 * 2 + 1;
	int minL = 1e9;
	int minR = 1e9;

	int l = 0;
	int r = N - 1;
	while (l < r)
	{
		int sum = nums[l] + nums[r];
		int abssum = abs(sum);

		if (minValue > abssum)
		{
			minValue = abssum;
			minL = nums[l];
			minR = nums[r];
		}

		if (0 > sum)
			++l;
		else if (0 < sum)
			--r;
		else
			break;
	}

	cout << minL << ' ' << minR;

	return 0;
}
