#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <stack>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 50만개... 괜찮으려나?
	int N;
	cin >> N;

	vector<int> towers(N);
	for (int& i : towers)
		cin >> i;

	stack<int> s;
	for (int i = N - 1; i >= 0; --i)
	{
		// 이전에 쏜 레이저가 부딪힌 경우
		while (!s.empty() && towers[s.top()] < towers[i])
		{
			// 해당 레이저 칸에 현재 인덱스 기록 후 pop
			towers[s.top()] = i + 1;
			s.pop();
		}

		// 현재 탑에서 레이저 쏘기
		s.push(i);
	}

	// 남은 탑 => 레이저가 부딪히지 못하였어요.
	while (!s.empty())
	{
		int idx = s.top();
		s.pop();

		towers[idx] = 0;
	}

	for (int& i : towers)
		cout << i << ' ';

	return 0;
}
