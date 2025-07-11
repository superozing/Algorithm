#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
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
	vector<bool> visited(N + 1);

	q.push({ N, 0 });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		cur.second++;

		if (cur.first % 3 == 0 && !visited[cur.first / 3])
		{
			if (cur.first / 3 == 1)
			{
				cout << cur.second;
				break;
			}
			visited[cur.first / 3] = true;
			q.push({ cur.first / 3, cur.second });
		}
		if (cur.first % 2 == 0 && !visited[cur.first / 2])
		{
			if (cur.first / 2 == 1)
			{
				cout << cur.second;
				break;
			}

			visited[cur.first / 2] = true;
			q.push({ cur.first / 2, cur.second });
		}

		cur.first--;
		if (cur.first == 1 && !visited[cur.first])
		{
			cout << cur.second;
			break;
		}
		visited[cur.first] = true;
		q.push(cur);
	}

	return 0;
}
