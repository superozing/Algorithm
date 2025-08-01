#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <string>

#define endl '\n'

using namespace std;

int N, M;
int digitCnt;
int answer;

vector<bool> digit;
string s;

void Backtracking()
{
	// 비교 조건
	if (s.length() >= digitCnt - 1)
	{
		int cur = stoi(s);
		answer = min(answer, abs(cur - N) + (int)s.length());

		//cout << "cur: " << s << ", ans: " << answer << endl;

		// 종료 조건
		if (s.length() == digitCnt + 1)
			return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (digit[i])
			continue;

		s += '0' + i;
		Backtracking();
		s.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	digitCnt = to_string(N).length();
	digit.resize(10);

	// 고장난 버튼 체크
	for (int i = 0; i < M; ++i)
	{
		int in;
		cin >> in;
		digit[in] = true;
	}

	// 1. 리모컨 +, - 을 눌러 냅다 이동
	answer = abs(100 - N);

	// 1-1) 0 false인 경우 0에서 해당 위치로 +, -을 눌러 이동
	if (!digit[0])
		answer = min(N + 1/*0을 누른 1회 추가*/, answer);

	// 2. 리모컨 숫자를 눌러 근처로 이동한 후 + - 로 이동
	// 2-1) 고장나지 않은 숫자들로 만들 수 있는 수 중 N에 가장 가까운 수를 찾아야 한다.
	//		이건 뭘로 찾아야 하려나...? 백트래킹?
	for (int i = 1; i < 10; ++i)
	{
		if (digit[i])
			continue;

		s += '0' + i;
		Backtracking();
		s.pop_back();
	}

	cout << answer;

	return 0;
}
