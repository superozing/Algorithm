#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class BAEKJOON
{
	int			N;	 // 수열 A의 크기

	vector<int> arr; // 수열
	vector<int> res; // 결과 수열이 오름차순으로 담길 벡터 res

public:
	void init();
	void progress();

public:
	BAEKJOON() { init(); }
	~BAEKJOON() {}
};


void BAEKJOON::init()
{
	cin >> N;

	arr.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];
}

void BAEKJOON::progress()
{
	int arrCount = 0;

	// 첫 원소를 담아서 for문 안에서 비교해줄 수 있도록 함
	res.push_back(arr[0]);
	++arrCount;

	for (int i = 1; i < N; ++i)
	{
		if (res.back() < arr[i])
		{
			// 만약 arr[i]가 마지막 원소보다 클 경우에는 정상적으로 오름차순으로 정렬되고 있기에 뒤에 넣어줌.
			res.push_back(arr[i]);

			// 수열의 개수가 1개 증가
			++arrCount;
		}
		else
		{
			// 만약 arr[i]가 마지막 원소보다 작을 경우에는, 
			// arr[i]보다 처음으로 큰 부분의 인덱스를 찾아서 오름차순으로 정렬시켜줌.
			int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
			res[idx] = arr[i];
		}
	}

	// res에 들어있는 배열의 원소가 LIS를 구성하는 원소는 아니라는 점을 주의하래요.
	// 먼저 들어온 원소보다 lower_bound로 찾은 위치가 더 이전일 수 있기 때문이래요.

	cout << arrCount;

}

int main()
{
	BAEKJOON b;
	b.progress();

	return 0;
}