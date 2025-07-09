#include <iostream>
#include <algorithm>

#include <queue>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i < N + 1; ++i)
		q.push(i);

	cout << '<';

	int k = 0;
	while (!q.empty())
	{
		++k;

		int cur = q.front();
		q.pop();

		if (k != K)
		{
			q.push(cur);
			continue;
		}
		
		k = 0;

		cout << cur;
		if (!q.empty())
			cout << ", ";
	}

	cout << '>';

	return 0;
}