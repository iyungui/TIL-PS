#include <bits/stdc++.h>

using namespace std;

struct Job {
    int number, req, t;
    bool operator>(const Job& other) const {
        if (t != other.t) return t > other.t;
        if (req != other.req) return req > other.req;
        return number > other.number;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    
    priority_queue<Job, vector<Job>, greater<Job>> pq;
    int curTime = 0, sum = 0, idx = 0;
    
    while (idx < jobs.size() || !pq.empty()) {
        while (idx < jobs.size() && jobs[idx][0] <= curTime) {
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
        if (pq.empty()) {
            curTime = jobs[idx][0];
        } else {
            Job cur = pq.top(); pq.pop();
            curTime += cur.t;
            sum += (curTime - cur.req);
        }
    }
    return sum / jobs.size();
}