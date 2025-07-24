#include <iostream>
#include <algorithm>
#include <cmath>

#include <string>

#define endl '\n'

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	cout << A + B - C << endl;
	cout << stoi(to_string(A) + to_string(B)) - C;


	return 0;
}
