/*
양의 정수 x가 주어졌을 때, x의 제곱근을 소수점 아래를 버린 가장 가까운 정수로 반환하세요. 반환되는 정수는 음수가 아니어야 합니다.

이때, 내장된 거듭제곱 함수나 연산자를 사용할 수 없습니다.

예를 들어, C++에서 pow(x, 0.5) 또는 파이썬에서 x ** 0.5와 같은 연산을 사용할 수 없습니다.
*/


class Solution 
{
public:
    
    int mySqrt(int x) 
    {
        // 어떻게 제곱근을 구해야 할까요.
        // 사실은 제곱근을 구하는게 아닐 수 있다.
        // 1~x까지 이분탐색을 하면
        // mid * mid 해서 가장 x에 가까운 값을 지닌 무언가를 반환하면 되는 것 같아요.
        
        int l = 0;
        int r = x;
        
        while (l <= r)
        {
            long long m = (l + r) / 2;
            
            if (m * m > x)
                r = m - 1;
            else if (m * m < x)
                l = m + 1;
            else
                return m;
        }
        
        return r;
    }
};