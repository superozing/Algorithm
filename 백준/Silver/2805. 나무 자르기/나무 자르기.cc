// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Boj
{
public:
    long long n; // 나무의 수
    long long length; // 필요한 나무의 길이
    vector<long long> trees;

    void input()
    {
        cin >> n >> length;
        trees.resize(n);
        for (long long i = 0; i < n; ++i)
        {
            cin >> trees[i];
        }
    }

    void progress()
    {
        long long l = 0;
        long long r = 2000000000; // 20억

        while (l <= r)
        {
            long long m = (l + r) / 2;
            long long cutTree = GetCuttingTree(m);
            if (cutTree < length)
                r = m - 1;
            else if (cutTree > length)
                l = m + 1;
            else
            {
                cout << m;
                return;
            }
        }
        cout << r;
    }


private:
    long long GetCuttingTree(long long height)
    {
        long long acc = 0;

        for (long long i = 0; i < n; ++i)
            acc += (trees[i] - height > 0) ? trees[i] - height : 0;

        return acc;
    }
};

int main()
{
    Boj boj;
    boj.input();
    boj.progress();

    return 0;
}
