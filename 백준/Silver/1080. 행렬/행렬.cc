#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

using Mat = vector<vector<bool>>;

void Reverse(Mat& m, int _y, int _x)
{
	for (int y = _y; y < _y + 3; ++y)
	for (int x = _x; x < _x + 3; ++x)
		m[y][x] = !m[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	Mat src(N, vector<bool>(M));
	Mat dest(N, vector<bool>(M));

	char in;

	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		cin >> in;
		src[y][x] = (in == '1');
	}


	for (int y = 0; y < N; ++y)
	for (int x = 0; x < M; ++x)
	{
		cin >> in;
		dest[y][x] = (in == '1');
	}

	// 좌상단부터 N-3 M-3까지 돌면 될 듯
	// 매 요소 순회마다 src와 dest가 다르면 행렬 바꾸기.
	// 만약 모든 순회가 끝난 이후에도 다르면 실패해요. -1반환

	int answer = 0;
	for (int y = 0; y < N - 2; ++y)
	for (int x = 0; x < M - 2; ++x)
	{
		if (src[y][x] != dest[y][x])
		{
			++answer;
			Reverse(src, y, x);
		}
	}

	cout << (src == dest ? answer : -1);

	return 0;
}
