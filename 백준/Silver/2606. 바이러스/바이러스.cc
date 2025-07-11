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

	int N, M;
	cin >> N >> M;

	vector<vector<int>> net(N + 1);
	vector<bool> visited(N + 1);

	while (M--)
	{
		int s, d;
		cin >> s >> d;

		net[s].push_back(d);
		net[d].push_back(s);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i : net[cur])
		{
			if (visited[i])
				continue;

			q.push(i);
			visited[i] = true;
		}
	}

	int answer = 0;
	for (int i = 2; i < visited.size(); ++i)
		if (visited[i])
			++answer;

	cout << answer;

	return 0;
}
 