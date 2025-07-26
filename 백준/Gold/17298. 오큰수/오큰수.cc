#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

struct Num
{
	int n, idx;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// A = [3, 5, 2, 7, 8]
	// 오른 쪽 부터 탐색하는 게 좋아보인다
	// 왼 쪽으로 옮기면서 오큰수 구하기


	int N;
	cin >> N;
	vector<int> nums(N);
	vector<Num> nge(N); // n: 오큰수 idx: 오큰수의 인덱스

	for (int& i : nums)
		cin >> i;

	nge[N - 1] = { -1, -1 };

	for (int i = N - 2; i >= 0; --i)
	{
		// 현재 수가 오른 쪽 수와 같다면
		// 오른 쪽의 오큰수가 현재 값의 오큰수가 된다.
		if (nums[i] == nums[i + 1])
			nge[i] = nge[i + 1];
		// 현재 수가 오른 쪽 수보다 작다면
		// 오른 쪽이 오큰수가 됨
		else if (nums[i] < nums[i + 1])
			nge[i] = { nums[i + 1], i + 1 };
		// 현재 수가 오른 쪽 수보다 크다면
		else
		{
			// 오른 쪽의 오큰수 가져오기
			Num cur = nge[i + 1];

			while (true)
			{
				// 이미 최대로 큰 수였다면?
				if (cur.idx == -1)
				{
					// 현재 수가 제일 큰 것
					nge[i] = { -1, -1 };
					break;
				}
				// 현재 수가 오른 쪽의 오큰수보다 작다면
				else if (nums[i] < cur.n)
				{
					// 그 수를 오큰수로 삼기
					nge[i] = cur;
					break;
				}
				//	현재 수가 오른 쪽의 오큰수보다 크다면
				else if (nums[i] > cur.n)
				{
					// 그 수의 오큰수와 비교
					cur = nge[cur.idx];
				}
				//	현재 수가 오른 쪽의 오큰수와 같다면
				else
				{
					// 오큰수의 오큰수를 오큰수로 삼기
					nge[i] = nge[cur.idx];
					break;
				}
			}
		}
	}

	for (auto& i : nge)
		cout << i.n << ' ';

	return 0;
}
