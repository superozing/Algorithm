#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 빨, 초, 파 중 하나의 색으로 집을 칠할 수 있다
	// 각 집마다 칠하는 비용이 있다.
	// 모든 집을 규칙에 맞게 칠했을 때 최소 비용 구하기.

	/* 규칙
		1번 집의 색은 2번 집의 색과 같지 않아야 한다.
		N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
		i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
	*/

	int N;
	cin >> N;

	vector<int[3]> houses(N);

	for (auto& house : houses)
	{
		for (int i = 0; i < 3; ++i)
			cin >> house[i];
	}

	// dp[i][j] = i 번째 집에 색상 j를 반드시 칠할 경우, 칠할 수 있는 최소값

	for (int i = 1; i < houses.size(); ++i)
	{
		auto& curHouse = houses[i];
		auto& prevHouse = houses[i - 1];

		curHouse[0] += min(prevHouse[1], prevHouse[2]);
		curHouse[1] += min(prevHouse[0], prevHouse[2]);
		curHouse[2] += min(prevHouse[0], prevHouse[1]);
	}

	auto& answerHouse = houses.back();

	cout << min(min(answerHouse[0], answerHouse[1]), answerHouse[2]);

	return 0;
}
