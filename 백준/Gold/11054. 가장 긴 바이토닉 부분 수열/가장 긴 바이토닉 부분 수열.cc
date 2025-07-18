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
	vector<int> asc(N);
	vector<int> des(N);

	vector<int> ascStack;
	vector<int> desStack;

	for (int& i : in)
		cin >> i;

	for (int i = 0; i < N; ++i)
	{
		if (ascStack.empty() || ascStack.back() < in[i])
			ascStack.push_back(in[i]);
		else if (ascStack.back() > in[i])
			*lower_bound(begin(ascStack), end(ascStack), in[i]) = in[i];
		
		if (desStack.empty() || desStack.back() < in[N - i - 1])
			desStack.push_back(in[N - i - 1]);
		else if (desStack.back() > in[N - i - 1])
			*lower_bound(begin(desStack), end(desStack), in[N - i - 1]) = in[N - i - 1];

		asc[i] = ascStack.size();
		des[N - i - 1] = desStack.size();
	}

	int answer = 0;
	for (int i = 0; i < N; ++i)
		answer = max(asc[i] + des[i] - 1, answer);

	cout << answer;

	return 0;
}
 