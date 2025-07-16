#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

using Mat = vector<vector<int>>;

Mat in;
int N; 
long long B;

Mat MulMatrix(Mat m1, Mat m2)
{
	Mat newMat(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	for (int k = 0; k < N; ++k)
		newMat[i][j] += m1[i][k] * m2[k][j];

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		newMat[i][j] %= 1000;

	return newMat;
}

Mat PowMatrix(Mat m)
{
	Mat newMat(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	for (int k = 0; k < N; ++k)
		newMat[i][j] += m[i][k] * m[k][j];

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		newMat[i][j] %= 1000;

	return newMat;
}

Mat DivideAndConquer(long long depth)
{
	if (depth == 1)
		return in;

	Mat cur = DivideAndConquer(depth / 2);

	if (depth % 2)
		return MulMatrix(PowMatrix(cur), in);

	return PowMatrix(cur);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 제곱 하니까 분할 정복 생각이 나요.
	// B 존나 크다
	cin >> N >> B;

	in.resize(N, vector<int>(N));

	for (int y = 0; y < N; ++y)
	for (int x = 0; x < N; ++x)
	{
		cin >> in[y][x];
		in[y][x] %= 1000;
	}

	Mat answer = DivideAndConquer(B);

	for (auto& v : answer)
	{
		for (int& i : v)
			cout << i << ' ';

		cout << endl;
	}

	return 0;
}
 