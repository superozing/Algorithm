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

	// 루트 없는 트리 주고 -> 사실 트리가 아님
	// 트리 루트 1이라고 정했을 때 -> 사실 트리가 아님
	// 각 노드의 부모 구하기 -> 노드에 방문했을 때 visited에 이전 노드 기록하기
	// BFS 하고 이전 방문 노드를 부모로 삼으면 간단하게 해결 될 것 같은데용?

	int N;
	cin >> N;

	vector<vector<int>> tree(N + 1);
	vector<int> visited(N + 1);

	int a, b;
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	queue<int> q;
	visited[1] = 1;

	q.push(1);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : tree[cur])
		{
			if (!visited[next])
			{
				visited[next] = cur;
				q.push(next);
			}
		}
	}

	for (int i = 2; i < visited.size(); ++i)
		cout << visited[i] << endl;

	return 0;
}
 