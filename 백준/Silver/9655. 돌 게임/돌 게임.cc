#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	cout << (N % 2 == 0 ? "CY" : "SK");

	return 0;
}
