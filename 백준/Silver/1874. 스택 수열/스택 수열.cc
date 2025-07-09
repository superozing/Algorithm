#include <iostream>
#include <algorithm>
#include <cmath>

#include <stack>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int curPushNum = 1;
	stack<int> s;
	string answer;

	while (N--)
	{
		int in;
		cin >> in;

		// 1. curPushNum보다 같거나 큰게 들어와
		if (in >= curPushNum)
		{
			// 그러면 curPushNum을 늘리면서 s에 넣고, 빼면서 answer에 기록하기
			while (in >= curPushNum)
			{
				s.push(curPushNum++);
				answer += "+\n";
			}

			s.pop();
			answer += "-\n";
		}
		// 2. curPushNum보다 작은게 들어와
		else
		{
			// 그러면 스택을 확인해야 한다.
			// 아니라면 NO 출력하고 예외처리
			if (s.top() != in)
			{
				answer = "NO";
				break;
			}

			// 만약 스택 맨 위에 있는게 in과 같으면 빼면서 answer에 기록
			s.pop();
			answer += "-\n";
		}
	}

	cout << answer;

	return 0;
}