#include <iostream>
#include <algorithm>
#include <cmath>

#include <unordered_map>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> um;

	string answer;
	answer.reserve(20 * N);

	string in;
	while (N--)
	{
		cin >> in;
		cin >> um[in];
	}
	while (M--)
	{
		cin >> in;
		answer += um[in] + '\n';
	}

	cout << answer;

	return 0;
}
