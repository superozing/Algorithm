#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    vector<int> student(n + 2);
    
    for (int i : lost)
        student[i]--;
    
    for (int i : reserve)
        student[i]++;
    
    for (int i = 1; i < student.size(); ++i)
    {
        if (student[i] == 1)
        {
            if (student[i - 1] == -1)
                student[i - 1]++;
            else if (student[i + 1] == -1)
                student[i + 1]++;
        }
    }
    
    for (int i : student)
        if (i >= 0)
            ++answer;
    
    return answer - 2;
}