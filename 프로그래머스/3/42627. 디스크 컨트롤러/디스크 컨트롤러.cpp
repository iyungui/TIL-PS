#include <bits/stdc++.h>
using namespace std;

struct Job {
    int idx, req, time;
    bool operator<(const Job& other) const {
        // 소요시간 짧은 순
        if(time != other.time) return time > other.time;
        // 요청시간 빠른 순
        if(req != other.req) return req > other.req;
        // 작업번호 작은 순
        return idx > other.idx;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cur_time = 0;
    int i = 0;
    int n = jobs.size();
    
    priority_queue<Job, vector<Job>> pq;
    sort(jobs.begin(), jobs.end());
    
    while(i < n || pq.size()) {
        while(i < n && cur_time >= jobs[i][0]) {
            pq.push({i, jobs[i][0], jobs[i][1]});
            i++;
        }
        if(pq.size()) {
            Job cur = pq.top(); pq.pop();
            cur_time += cur.time;
            answer += (cur_time - cur.req);
        }
        else cur_time = jobs[i][0];
    }
    return answer / n;
}