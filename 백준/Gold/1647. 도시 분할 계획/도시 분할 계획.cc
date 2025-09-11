#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

#define endl ('\n')

struct Edge
{
	int a, b, c;
};

vector<int> roots;

int Find(int a)
{
	if (roots[a] == a)
		return a;

	return roots[a] = Find(roots[a]);
}

void Union(int a, int b)
{
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB)
		return;

	if (rootA > rootB)
		swap(rootA, rootB);

	roots[rootB] = rootA;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// mst로 연결할 때, union find에 루트 번호가 단 두 개라면 도시가 분할된 것.
	
	// 1. 입력을 s, e, c 순서로 저장

	int N, M;
	cin >> N >> M;

	// 집이 두 개일 경우 예외처리
	if (N == 2)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<Edge> edges(M);
	for (auto& edge : edges)
		cin >> edge.a >> edge.b >> edge.c;

	// 유니온 파인드 루트 설정
	roots.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		roots[i] = i;

	// 간선 정렬
	sort(begin(edges), end(edges), 
		[](const Edge& a, const Edge& b)
		{
			return a.c < b.c;
		});

	int answer = 0;
	int nodeCount = N;

	// 모든 간선을 순회하며 최소 신장 트리 찾기
	for (auto& edge : edges)
	{
		// 사이클 발생 시 continue;
		if (Find(edge.a) == Find(edge.b))
			continue;

		Union(edge.a, edge.b);
		answer += edge.c;

		// 집합의 개수 감소
		nodeCount--;

		// 집합이 딱 두 개가 된 경우
		if (nodeCount == 2)
			break;
	}

	cout << answer;

	return 0;
}

