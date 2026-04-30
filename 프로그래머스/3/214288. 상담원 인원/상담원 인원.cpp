#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> clients[6];  // 상담유형별 고객들의 (상담요청시간, 소요시간)
// 상담유형별로 멘토 몇 명이 배정되었는지 담은 배열
int cnt[6];
int costs[6][22];   // [상담유형][멘토인원] 일 때 기다린 시간의 총합
int ret = 1e9;

// 상담유형이 type이고, 해당 상담유형에 mento_cnt가 배정된 경우,
// 해당 상담유형을 신청한 참가자들이 기다려야 하는 시간의 총합 구하기
int get_total_wait_time(vector<pair<int, int>> clients, int mento_cnt) {
    // 해당 유형을 선택한 참가자가 없는 경우
    if(clients.empty()) return 0;
    
    int total_wait_time = 0;
    
    // 현재 상담 중인 상담의 종료시간을 담은 우선순위 큐. (종료시간이 빠른 게 먼저오도록 정렬)
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // (reqs는 a를 기준으로 오름차순 이미 정렬되어있음)
    
    for(auto& c : clients) {
        // 현재 참가자의 상담요청 >= 시각 현재 상담중인 상담들 중 가장 빨리끝나는 상담의 종료시간
        while(pq.size() && c.first >= pq.top()) pq.pop();  // 현재 상담중인 상담의 종료처리
        
        // 바로 상담이 가능한 경우
        if((int)pq.size() < mento_cnt) {
            // 남은 멘토 자리에 배정
            pq.push(c.first + c.second);    // 상담 요청 시각 + 소요 시간
        }
        // 기다려야 하는 경우
        else {
            // 가장 빨리끝나는 상담의 종료시간 + 현재 요청한 상담 소요시간
            int t = pq.top(); pq.pop();
            int wait_time = t - c.first;
            total_wait_time += wait_time;
            pq.push(t + c.second);
        }
    }
    
    return total_wait_time;
}

int go(int k) {
    int total = 0;
    for(int i = 1; i <= k; i++) {
        total += costs[i][cnt[i]];
    }
    return total;
}

void dfs(int cur_type, int remain_mentos, int k) {
    if(cur_type == k) {
        cnt[cur_type] = remain_mentos;
        ret = min(ret, go(k));
        return;
    }
    // cur_type에 x명 멘토 배정
    for(int x = 1; x <= remain_mentos - (k - cur_type); x++) {
        cnt[cur_type] = x;
        dfs(cur_type + 1, remain_mentos - x, k);
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    ret = 1e9;   // 멘토인원을 적절히 배정했을 때 모든 참가자들이 상담을 받기까지 기다린 시간의 총합의 최솟값
    
    for(int i = 1; i <= k; i++) clients[i].clear();
    
    // parsing
    for(auto& r : reqs) {
        clients[r[2]].push_back({r[0], r[1]});
    }
    
    // 미리 모든 경우의 수를 구하기
    for(int t = 1; t <= k; t++) {
        for(int m = 1; m <= n - k + 1; m++) {
            costs[t][m] = get_total_wait_time(clients[t], m);
        }
    }
    
    // 현재 상담유형, 멘토 인원수, 상담유형 수
    dfs(1, n, k);
    return ret;
}