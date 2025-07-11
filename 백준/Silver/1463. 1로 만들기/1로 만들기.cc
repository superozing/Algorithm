#include <iostream>
#include <algorithm>
#include <cmath>

#include <queue>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	queue<pair<int, int>> q;

	q.push({ N, 0 });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		cur.second++;

		if (cur.first % 3 == 0)
		{
			if (cur.first / 3 == 1)
			{
				cout << cur.second;
				break;
			}

			q.push({ cur.first / 3, cur.second });
		}
		if (cur.first % 2 == 0)
		{
			if (cur.first / 2 == 1)
			{
				cout << cur.second;
				break;
			}

			q.push({ cur.first / 2, cur.second });
		}
		
		cur.first--;
		if (cur.first == 1)
		{
			cout << cur.second;
			break;
		}
		q.push(cur);
	}

	return 0;
}
