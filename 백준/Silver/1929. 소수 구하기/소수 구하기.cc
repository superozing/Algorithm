#include <iostream>
#include <algorithm>

#include <vector>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;
	 
	vector<bool> v(N + 1);
	v[0] = true;
	v[1] = true;

	for (int i = 2; i * i < v.size(); ++i)
	{
		if (v[i])
			continue;

		for (int j = i * 2; j < v.size(); j += i)
			v[j] = true;
	}

	for (int i = M; i < v.size(); ++i)
		if (!v[i])
			cout << i << endl;

	return 0;
}