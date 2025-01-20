#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<char>> grid;

int main()
{
	cin >> N >> M;
	grid.resize(N, vector<char>(M));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> grid[i][j];

	int answer = 999;

	for (int n = 0; n <= N - 8; ++n)
	{
		for (int m = 0; m <= M - 8; ++m)
		{
			int whiteStartCnt = 0;
			char cur = 'W';

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					if (grid[i + n][j + m] != cur)
						++whiteStartCnt;

					if (cur == 'W')
						cur = 'B';
					else
						cur = 'W';
				}
				if (cur == 'W')
					cur = 'B';
				else
					cur = 'W';
			}

			int blackStartCnt = 0;
			cur = 'B';

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					if (grid[i + n][j + m] != cur)
						++blackStartCnt;

					if (cur == 'W')
						cur = 'B';
					else
						cur = 'W';
				}
				if (cur == 'W')
					cur = 'B';
				else
					cur = 'W';
			}

			answer = min(answer, min(blackStartCnt, whiteStartCnt));
		}
	}

	cout << answer;

	return 0;
}