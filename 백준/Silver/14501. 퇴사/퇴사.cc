#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BAEKJOON_2805 // 퇴사
{
public:
	int			n; // 퇴사까지 남은 날짜
	vector<int> T; // 상담 진행 기간
	vector<int> P; // 상담으로 얻는 이익

public:
	void init();
	int progress();
};



void BAEKJOON_2805::init()
{
	cin >> n;
	int buf = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> buf;
		T.push_back(buf);

		cin >> buf;
		P.push_back(buf);
	}
}

int BAEKJOON_2805::progress()
{
	// DP를 이용한 풀이가 필요하다...?
	// 뒤 쪽 부터 이익을 계산하며 채워나가요.
	vector<int> dp(n, -1);

	// 마지막 날 먼저 계산
	int t = T.back();
	int p = P.back();

	if (t > 1) // -> 이 경우 상담 진행 불가
		dp[n - 1] = 0;
	else
		dp[n - 1] = p;

	for (int i = n - 2; i >= 0; --i)
	{
		t = T[i];
		p = P[i];

		// 0. 일단 이 날짜에 상담이 가능한지를 판단해야 한다.
		if (i + t > n)
		{
			dp[i] = dp[i + 1];
			continue;
		}

		// 1. 현재 날짜를 실행시키는게 더 많은 이득을 취하는지, 아니면 현재 날짜를 실행시키지 않는게 더 많은 이득을 취하는지를 계산해야 한다.
		// 이 때, t만큼 앞으로 이동한 값과 자신의 값을 더한 것이 더 큰지와 i + 1의 값을 비교해서 집어넣는다.
		if (i + t > n - 1) // -> 이 경우, 자신과 이전까지의 합을 비교해준다
			dp[i] = dp[i + 1] > p ? dp[i + 1] : p;
		else
			dp[i] = dp[i + 1] > dp[i + t] + p ? (dp[i + 1]) : (dp[i + t] + p);
	}

	return dp.front();
}

int main()
{
	BAEKJOON_2805 b;
	b.init();
	cout << b.progress();
	return 0;
}