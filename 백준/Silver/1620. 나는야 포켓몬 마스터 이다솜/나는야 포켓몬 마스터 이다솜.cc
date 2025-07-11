#include <iostream>
#include <algorithm>
#include <cmath>

#include <string>
#include <vector>
#include <unordered_map>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<string> v(N + 1);
	unordered_map<string, int> um;

	for (int i = 1; i < N + 1; ++i)
	{
		cin >> v[i];
		um.insert({ v[i] , i });
	}

	while (M--)
	{
		string in;
		cin >> in;
		if ('0' <= in[0] && in[0] <= '9')
			cout << v[stoi(in)] << endl;
		else
			cout << um[in] << endl;
	}
	

	return 0;
}
