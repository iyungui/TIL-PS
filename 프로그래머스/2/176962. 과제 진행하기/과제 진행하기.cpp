#include <bits/stdc++.h>

using namespace std;

struct Job {
    string name;
    int start, remain;
};

int timeToMin(string& s) {
    int h = stoi(s.substr(0, 2)), m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

vector<string> solution(vector<vector<string>> plans) {

    vector<string> answer;
    vector<Job> jobs;
    for(auto& p : plans) {
        jobs.push_back({p[0], timeToMin(p[1]), stoi(p[2])});
    }
    // 과제 시작시간 기준 오름차순 정렬
    sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
        return a.start < b.start;
    });
    
    Job cur = jobs[0];
    int cur_time = jobs[0].start;
    
    stack<Job> stk;
    // stk.push(cur);
    
    for(int i = 1; i < (int)jobs.size(); i++) {
        // 이전 과제 시작시간과 현재과제 시작시간의 차이
        int gap = jobs[i].start - cur_time;
        
        // 이전 과제 완료시킬 수 있는 경우
        if(cur.remain <= gap) {
            cur_time += cur.remain;
            answer.push_back(cur.name);
            
            // 여유시간 계산
            int remaining = jobs[i].start - cur_time;
            while(remaining > 0 && stk.size()) {
                // 여유시간 동안 스택에 있는 과제들 처리
                Job& top = stk.top();
                // 스택에 있는 작업이 바로 완료되는 경우
                if(top.remain <= remaining) {
                    remaining -= top.remain;
                    answer.push_back(top.name);
                    stk.pop();
                }
                // 완료되지는 않는 경우(잔여시간만 업데이트)
                else {
                    top.remain -= remaining;
                    remaining = 0;  // break와 동일
                }
            }
        }
        
        // 현재 과제 중단 후 push
        else {
            cur.remain -= gap;
            stk.push(cur);
        }
        
        // 현재과제 시작시간으로 갱신. cur 갱신
        cur_time = jobs[i].start;
        cur = jobs[i];
    }
    
    // 마지막 과제 완료
    answer.push_back(cur.name);
    
    // 스택에 남은 과제들 순서대로 처리
    while(stk.size()) {
        answer.push_back(stk.top().name); stk.pop();
    }
    
    return answer;
}