#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    // 가로 길이와 세로 길이는 모두 3 이상이어야 해요
    // 가로 길이 >= 세로 길이.
    
    // 갈색의 개수가 테두리를 전부 감싸면서 개수가 brown과 같다면...
    
    // 10 2
    // 가로의 길이가 3일 경우: (10 - (3 - 2) * 2) / 2 = 세로 길이.
    // 이게 갈색 + 노란색이면 정답이겠죠?
    
    int y = 0;
    
    for (int x = 3; x < brown; ++x)
    {
        y = (brown - (x - 2) * 2) / 2;
        
        if (x * y == brown + yellow)
            return vector<int>{max(x, y), min(x, y)};
    }
    
    return vector<int>();
}