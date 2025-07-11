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

	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	sort(begin(v), end(v));

	int answer = v.front();

	for (int i = 1; i < v.size(); ++i)
	{
		v[i] += v[i - 1];
		answer += v[i];
	}

	cout << answer;

	return 0;
}
