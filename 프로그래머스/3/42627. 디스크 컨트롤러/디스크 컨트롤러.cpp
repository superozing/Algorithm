#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct task
{
    long long idx, start, weight;
};

struct pqcmp
{
    bool operator()(task& a, task& b)
    {
        return a.weight != b.weight ? a.weight > b.weight : a.start != b.start ? a.start > b.start : a.idx > b.idx;
    }
};

struct veccmp
{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
    }
};

int solution(vector<vector<int>> jobs) 
{
    long long answer = 0;
    long long idx = 0;
    long long second = 0;
    
    task curTask{-1, 0, 0};
    
    vector<long long> taskStartTime(jobs.size());
    priority_queue<task, vector<task>, pqcmp> pq;
    
    sort(begin(jobs), end(jobs), veccmp());
    
    while (true)
    {
        // 1. 현재 초에 맞는 업무를 대기 큐에 추가하기
        while (idx < jobs.size() && jobs[idx][0] == second)
        {
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            ++idx;
        }
        
        // 2. 현재 업무가 진행 중일 경우, 시간 누적하기
        if (curTask.idx != -1)
        {
            // 업무가 끝났나요?
            if (taskStartTime[curTask.idx] + curTask.weight == second)
            {
                // answer에 시간 누적
                answer += second - curTask.start;
                
                // 업무 초기화
                curTask.idx = -1;
                
                // 종료 시점
                if (pq.empty() && jobs.size() == idx)
                    break;
            }
        }
        
        // 3. 현재 업무가 진행 중이 아닐 경우, 새로운 업무 실행하기
        if (curTask.idx == -1 && !pq.empty())
        {
            curTask = pq.top();
            pq.pop();
            
            // 업무 시작 시간 기록
            taskStartTime[curTask.idx] = second;
        }
        
        // 4. 초 누적
        ++second;
    }
    
    
    
    return answer / jobs.size();
}