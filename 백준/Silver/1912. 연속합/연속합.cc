#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int N;
	cin >> N;

	// "연속된" 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합

	// 매 원소를 방문할 때 마다 answer 에 더 큰 수열의 합을 저장하면 되겠어요.
	// 만약 원소를 더할 때, 수열의 값이 0보다 적어질 경우 수열의 값을 0으로 초기화 하고 다음 값을 고르면 되겠어요.

	// 굳이 dp를 사용해야 하는가?

	int answer = -1001;
	
	int sum = 0;

	while (N--)
	{
		int cur;
		cin >> cur;
		
		sum += cur;
		answer = max(answer, sum);

		if (sum < 0)
			sum = 0;
	}

	cout << answer;

	return 0;
}
