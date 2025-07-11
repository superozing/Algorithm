#include <iostream>
#include <algorithm>
#include <cmath>

#include <string>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	string s;
	cin >> s;

	// 약간 콤보 느낌으로
	// I가 나왔을 때 콤보 시작
	// I 이후에 OI가 순서대로 나올 때 콤보가 점점 쌓이는거죠
	// 예를 들어 IOI는 1콤보
	// IOIOI는 2콤보
	// IOIOIOI는 3콤보
	// 이 이후에 다른 단어가 연속으로 나와서 콤보가 끊길 경우 I가 나올 때 까지 또 콤보를 0으로 만들고..
	// P1일 경우에는 그렇게 하면 되는데,
	// P2의 경우에는 조금 다르겠죠?
	// 예를 들어 IOI가 1콤보라면 P2의 경우에는 1 - 1이니까 0콤보인거죠
	// 그래서 IOIOI라면 2콤보니까 P2의 경우에는 2 - 1 이니까 1콤보인거고
	// 이후는 똑같아요.
	// 그래서 나중에 콤보 개수를 합해서 반환하면 될 듯.
	//OOIOIOIOIIOII

	int combo = -N + 1;
	bool isComboing = false;
	bool isOrderI = true;

	int answer = 0;

	for (char c : s)
	{
		if (!isComboing)
		{
			if (c == 'I')
			{
				isComboing = true;
				isOrderI = false;
			}
		}
		else
		{
			// 콤보 유지
			if (!isOrderI && c == 'O')
			{
				isOrderI = true;
			}
			else if (isOrderI && c == 'I')
			{
				isOrderI = false;
				++combo;
			}
			// 콤보 끊김
			else if (!isOrderI && c == 'I')
			{
				answer += combo > 0 ? combo : 0;
				combo = -N + 1;
				isOrderI = false;
			}
			else if (isOrderI && c == 'O')
			{
				answer += combo > 0 ? combo : 0;
				combo = -N + 1;
				isComboing = false;
				isOrderI = true;
			}
		}
	}

	answer += combo > 0 ? combo : 0;
	cout << answer;

	return 0;
}
