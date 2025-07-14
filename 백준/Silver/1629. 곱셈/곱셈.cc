#include <iostream>
#include <algorithm>
#include <cmath>

#define endl '\n'

using namespace std;

long long A, B, C;

long long Div(int cur)
{
	if (cur == 1)
		return A;

	long long k = Div(cur / 2);

	if (cur % 2)
		return k * k % C * A % C;

	return k * k % C;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B >> C;

	A %= C;
	
	cout << Div(B);
	
	return 0;
}
 