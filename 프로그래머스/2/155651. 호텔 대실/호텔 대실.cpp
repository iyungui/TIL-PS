#include <bits/stdc++.h>

using namespace std;

int timeToMin(string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    // 시작시각, 종료시각으로 파싱
    vector<pair<int, int>> v;
    for(auto& b : book_time) v.push_back({timeToMin(b[0]), timeToMin(b[1])});
    // 시작시각 기준 오름차순 정렬
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq; // 현재 대실 중인 객실을 담은 큐
    
    for(auto& [st, ed] : v) {
        // 퇴실처리
        while(pq.size() && pq.top() <= st) {
            pq.pop();
        } 
        pq.push(ed + 10);
        answer = max(answer, (int)pq.size());
    }
    
    return answer;
}