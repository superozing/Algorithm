#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

#define endl '\n'

using namespace std;

struct file
{
	int priority;
	bool isTarget;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		 
		queue<file> q;
		vector<int> v;

		for (int i = 0; i < N; ++i)
		{
			int in;
			cin >> in;
			q.push({ in, i == M });
			v.push_back(in);
		}

		sort(begin(v), end(v));

		int answer = 0;

		bool endOfSearch = false;
		while (!endOfSearch)
		{

			file cur = q.front();
			q.pop();

			// cout << "cur answer: " << answer << endl;
			// cout << "cur file priority: " << cur.priority << ", isTarget: " << cur.isTarget << endl;
			// cout << "cur top priority: " << v.back() << endl << endl;

			if (cur.priority == v.back())
			{
				++answer;
				v.pop_back();

				if (cur.isTarget)
					endOfSearch = true;
			}
			else
				q.push(cur);
		}

		cout << answer << endl;
	}

	return 0;
}