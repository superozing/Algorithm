#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <set>

#define endl '\n'

using namespace std;

struct num
{
	int num;
	int cnt;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int avg = .0f;
	int bias = 4000;

	vector<num> cnt(8002);
	for (int i = 0; i < cnt.size(); ++i)
		cnt[i].num = i - bias;

	vector<int> val;
	val.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		int in;
		cin >> in;
		avg += in;
		val.push_back(in);
		cnt[in + bias].cnt++;
	}

	sort(begin(val), end(val));
	sort(begin(cnt), end(cnt), [](const num& a, const num& b) 
		{
			return a.cnt == b.cnt ? a.num < b.num : a.cnt > b.cnt;
		});

	cout << (int)round(avg / (float)N) << endl;
	cout << val[val.size() / 2] << endl;
	cout << (cnt[0].cnt == cnt[1].cnt ? cnt[1].num : cnt[0].num) << endl;
	cout << val.back() - val.front() << endl;

	return 0;

}