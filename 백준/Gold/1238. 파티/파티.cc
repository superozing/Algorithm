#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

struct Node
{
	int dest;
	int time;
};

struct cmp
{
	bool operator() (const Node& a, const Node& b)
	{
		return a.time > b.time;
	}
};



int N, M, X;

void Dijkstra(vector<vector<Node>>& nodes, vector<int>& times)
{
	priority_queue<Node, vector<Node>, cmp> pq;

	pq.push({ X, 0 });

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (times[cur.dest] < cur.time)
			continue;

		for (auto& next : nodes[cur.dest])
		{
			if (times[next.dest] > next.time + cur.time)
			{
				times[next.dest] = next.time + cur.time;
				pq.push({ next.dest, next.time + cur.time });
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 역방향 다익스트라?
	cin >> N >> M >> X;

	vector<vector<Node>> reverseNodes(N + 1);
	vector<vector<Node>> nodes(N + 1);

	while (M--)
	{
		int s, d, t;
		cin >> s >> d >> t;

		reverseNodes[d].push_back({ s, t });
		nodes[s].push_back({ d, t });
	}

	vector<int> reverseTimes(N + 1, 1e9);
	vector<int> times(N + 1, 1e9);

	Dijkstra(reverseNodes, reverseTimes);
	Dijkstra(nodes, times);

	times[X] = 0;
	reverseTimes[X] = 0;

	int maxValue = 0;
	for (int i = 1; i < N + 1; ++i)
		maxValue = max(maxValue, times[i] + reverseTimes[i]);

	cout << maxValue;

	return 0;
}
 