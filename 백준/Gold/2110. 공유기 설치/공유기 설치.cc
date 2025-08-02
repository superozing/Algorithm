#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 가장 인접한 두 공유기의 거리를 가능한 크게 구하기

	int N, C;
	cin >> N >> C;

	vector<int> houses(N);
	for (int& i : houses)
		cin >> i;

	sort(begin(houses), end(houses));

	// 집이 두 개일 경우: 첫 집 ~ 마지막 집이 최대 거리

	int l = 0;
	int r = houses.back() - houses.front();

	int answer = 0;

	while (l <= r)
	{
		int dist = (l + r) / 2;

		int routerCnt = 1;
		int src = 0;
		for (int i = 1; i < N; ++i)
		{
			// 이 거리로 가능한 경우
			if (houses[src] + dist <= houses[i])
			{
				++routerCnt;
				src = i;
			}
		}

		if (routerCnt < C)
			r = dist - 1;
		else
		{
			answer = dist;
			l = dist + 1;
		}
	}

	cout << answer;

	return 0;
}
