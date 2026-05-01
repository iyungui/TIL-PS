#include <bits/stdc++.h>

using namespace std;

// 다른 글자수 몇개인지 세기(비교)
bool cmp(string& a, string& b) {
    int cnt = 0;
    
    for(int i = 0; i < (int)a.size(); i++) {
        if(a[i] != b[i]) cnt++;
        if(cnt > 1) return 0;
    }
    
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    // target이 words에 없으면 0 리턴
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    // begin에서 특정단어까지 가는 최소 거리를 저장 
    unordered_map<string, int> dist;
    dist[begin] = 0;
    
    queue<string> q;
    q.push(begin);
    
    while(!q.empty()) {
        string cur = q.front(); q.pop();
        
        // cur이 target인 경우
        if(cur == target) return dist[cur];
        // cur -> 다음 단어 탐색
        for(auto& w : words) {
            // 이미 방문한 단어는 스킵
            if(dist.find(w) != dist.end()) continue;
            // 한글자만 다른 경우에만 탐색
            if(cmp(cur, w)) {
                // 거리 저장
                dist[w] = dist[cur] + 1;
                q.push(w);
            }
        }
        
    }
    
    return 0;   // 변환할 수 없는 경우
}