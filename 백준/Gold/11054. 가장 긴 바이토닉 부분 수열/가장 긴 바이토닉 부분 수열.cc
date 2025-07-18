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

	vector<int> in(N);
	vector<int> dp(N);

	for (int& i : in)
		cin >> i;

	vector<int> ascStack;
	vector<int> desStack;

	for (int i = 0; i < N; ++i)
	{
		if (ascStack.empty() || ascStack.back() < in[i])
			ascStack.push_back(in[i]);
		else
			*lower_bound(begin(ascStack), end(ascStack), in[i]) = in[i];
		
		if (desStack.empty() || desStack.back() < in[N - i - 1])
			desStack.push_back(in[N - i - 1]);
		else
			*lower_bound(begin(desStack), end(desStack), in[N - i - 1]) = in[N - i - 1];

		dp[i] += ascStack.size();
		dp[N - i - 1] += desStack.size();
	}

	cout << *max_element(begin(dp), end(dp)) - 1;

	return 0;
}
 