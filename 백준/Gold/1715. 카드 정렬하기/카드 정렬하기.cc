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

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; ++i)
	{
		int in;
		cin >> in;

		pq.push(in);
	}

	int answer = 0;
	while (pq.size() >= 2)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		pq.push(a + b);
		answer += a + b;
	}

	cout << answer;

	return 0;
}
