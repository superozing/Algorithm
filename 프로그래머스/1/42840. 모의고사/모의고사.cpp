#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> s1{1, 2, 3, 4, 5};
    vector<int> s2{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> s3{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;
    
    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == s1[i % s1.size()])
            answer1++;
        if (answers[i] == s2[i % s2.size()])
            answer2++;
        if (answers[i] == s3[i % s3.size()])
            answer3++;
    }
    
    int maxValue = max(answer1, max(answer2, answer3));
    
    vector<int> returnValue;
    
    if (maxValue == answer1)
        returnValue.push_back(1);
    if (maxValue == answer2)
        returnValue.push_back(2);
    if (maxValue == answer3)
        returnValue.push_back(3);
    
    return returnValue;
}