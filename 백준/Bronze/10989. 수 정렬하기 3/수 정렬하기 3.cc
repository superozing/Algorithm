#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(10001);

	while (N--)
	{
		int in;
		cin >> in;
		v[in]++;
	}

	for (int i = 1; i < v.size(); ++i)
		while (v[i]--)
			cout << i << '\n';

	return 0;
}