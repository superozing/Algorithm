#include <iostream>
#include <algorithm>
#include <cmath>

#define endl '\n'

using namespace std;

long long DivAndCon(int A, int B, int C, long long cur)
{
	if (cur == 1)
		return A;

	long long k = DivAndCon(A, B, C, cur / 2);

	if (cur % 2)
		return k * k % C * A % C;

	return k * k % C;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long A, B, C;
	cin >> A >> B >> C;
	
	A %= C;
	cout << DivAndCon(A, B, C, B);
	
	return 0;
}
 