#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

#define endl ('\n')

vector<vector<int>> nodes;
vector<int> vertecies;
vector<bool> visited;

int Backtracking(int cur)
{
	int vertexCount = 1;

	for (int i = 0; i < nodes[cur].size(); ++i)
	{
		int next = nodes[cur][i];

		if (!visited[next])
		{
			visited[next] = true;
			vertexCount += Backtracking(next);
		}
	}

	return vertecies[cur] = vertexCount;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어졌을 때,
	// 정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.

	// 그래프 순회를 해야 할 것 같아요.

	int N, R, Q; // 정점 수, 루트 번호, 쿼리 수
	cin >> N >> R >> Q;

	nodes.resize(N + 1);
	vertecies.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		// 양방향
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}

	visited[R] = true;
	Backtracking(R);

	while (Q--)
	{
		int in;
		cin >> in;
		cout << vertecies[in] << endl;
	}

	return 0;
}

