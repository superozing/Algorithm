#include <iostream>
#include <algorithm>

#include <queue>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<int> q;

	int lastnumber = -1;

	int N;
	cin >> N;

	while (N--)
	{
		string in;
		cin >> in;

		if (in == "push")
		{
			int i;
			cin >> i;
			q.push(i);
			lastnumber = i;
		}
		else if (in == "pop")
		{
			if (q.empty())
			{
				cout << -1 << endl;
				continue;
			}

			cout << q.front() << endl;
			q.pop();
		}
		else if (in == "size")
		{
			cout << q.size() << endl;
		}
		else if (in == "empty")
		{
			cout << (int)q.empty() << endl;
		}
		else if (in == "front")
		{
			cout << (q.empty() ? -1 : q.front()) << endl;
		}
		else if (in == "back")
		{
			cout << (q.empty() ? -1 : lastnumber) << endl;
		}
	}

	return 0;
}