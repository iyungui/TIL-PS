#include <bits/stdc++.h>

using namespace std;

struct Job {
    int num, req, t;
    
    bool operator>(const Job& other) const {
        if(t != other.t) return t > other.t;
        if(req != other.req) return req > other.req;
        return num > other.num;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<Job, vector<Job>, greater<Job>> pq;
    int idx = 0, time = 0, sum = 0;
    
    while (idx < jobs.size() || pq.size()) {
        while (idx < jobs.size() && time >= jobs[idx][0]) {
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
        if (idx < jobs.size() && pq.empty()) time = jobs[idx][0];
        else {
            Job cur = pq.top(); pq.pop();
            time += cur.t;
            
            sum += (time - cur.req);
        }
    }
    return sum / jobs.size();
}