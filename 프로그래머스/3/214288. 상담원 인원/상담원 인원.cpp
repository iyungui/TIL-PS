#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> clients[6];
int costs[6][22];
int ret, K, N;

int get_total_wait_time(const vector<pair<int, int>>& clients, int m) {
    if(clients.empty()) return 0;
    priority_queue<int, vector<int>, greater<int>> pq(m, 0);
    int total = 0;
    for(auto& c : clients) {
        int req = c.first;
        int time = c.second;
        int e = pq.top(); pq.pop();
        if(req < e) {
            total += (e - req);
            pq.push(e + time);
        }
        else {
            pq.push(req + time);
        }
    }
    return total;
}

void dfs(int cur_type, int remain, int cur_sum) {
    if(cur_type == K) {
        ret = min(ret, cur_sum + costs[cur_type][remain]);
        return;
    }
    // 남은 유형들에게 최소 1명씩 배정
    for(int i = 1; i <= remain - (K - cur_type); i++) {
        dfs(cur_type + 1, remain - i, cur_sum + costs[cur_type][i]);
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    K = k; N = n; ret = 1e9;
    for(auto& r : reqs) clients[r[2]].push_back({r[0], r[1]});
    // 상담 유형별 비용 계산
    for(int t = 1; t <= k; t++) {
        for(int m = 1; m <= n - k + 1; m++) {
            costs[t][m] = get_total_wait_time(clients[t], m);
        }
    }
    dfs(1, n, 0);
    return ret;
}