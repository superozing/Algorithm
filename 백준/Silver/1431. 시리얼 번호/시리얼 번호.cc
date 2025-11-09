#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

struct Guitar
{
    string s;
    int sum;
};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);


    // 기타를 시리얼 순서로 정렬하기
    // A - Z, 0 - 9

    // 짧은 것이 앞에
    // 길이가 같다면 모든 자리수 합이 작은 것이 앞에
    // 이후 사전순 비교

    // 비교함수 만드는 문제네요.

    int N;
    cin >> N;

    vector<Guitar> guitars(N);
    for (auto& guitar : guitars)
    {
        cin >> guitar.s;

        for (char c : guitar.s)
        {
            if ('1' <= c && c <= '9')
                guitar.sum += c - '0';
        }
    }

    sort(begin(guitars), end(guitars), 
        [](const Guitar& a, const Guitar& b)
        {
            if (a.s.length() != b.s.length())
                return a.s.length() < b.s.length();
            if (a.sum != b.sum)
                return a.sum < b.sum;
            return a.s < b.s;
        });

    for (auto& guitar : guitars)
        cout << guitar.s << endl;

    return 0;
}