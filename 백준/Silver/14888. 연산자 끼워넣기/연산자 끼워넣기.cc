#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;


int N;
vector<int> nums;
vector<int> operators;

int minValue = 1e9;
int maxValue = -1e9;

// 순서대로 +, -, *, /
int operCount[4]{};

void BackTracking()
{
	// 탈출 조건
	if (operators.size() == N - 1)
	{
		int cur = nums.front();

		for (int i = 0; i < operators.size(); ++i)
		{
			switch (operators[i])
			{
			case 0:
				cur += nums[i + 1];
				break;
			case 1:
				cur -= nums[i + 1];
				break;
			case 2:
				cur *= nums[i + 1];
				break;
			case 3:
				cur /= nums[i + 1];
				break;
			}
		}

		minValue = min(minValue, cur);
		maxValue = max(maxValue, cur);

		return;
	}


	for (int i = 0; i < 4; ++i)
	{
		if (operCount[i] > 0)
		{
			operators.push_back(i);
			operCount[i]--;
			
			BackTracking();

			operators.pop_back();
			operCount[i]++;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	nums.resize(N);
	
	for (auto& i : nums)
		cin >> i;

	for (int i = 0; i < 4; ++i)
		cin >> operCount[i];

	BackTracking();

	cout << maxValue << endl << minValue;

	return 0;
}
