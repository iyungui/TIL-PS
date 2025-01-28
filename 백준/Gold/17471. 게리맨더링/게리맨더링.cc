#include <bits/stdc++.h>
using namespace std;

int n, cnt, temp, a[11], b[11], visited[11], ret = INT_MAX;
vector<int> adj[11];

pair<int, int> go(int here, int color) {
    pair<int, int> p = {1, a[here]};
    visited[here] = 1;
    
    for(int there : adj[here]) {
        if(visited[there]) continue;
        if(b[there] != color) continue;
        pair<int, int> _temp = go(there, color);
        p.first += _temp.first;
        p.second += _temp.second;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];    // 각 구역의 인구수
    for(int i = 1; i <= n; i++) {
        cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            cin >> temp;
            adj[i].push_back(temp);
            adj[temp].push_back(i); // 양방향 간선.
        }
    }
    
    // 비트마스킹을 이용한 경우의 수
    for(int i = 1; i < (1 << n) - 1; i++) { // ?
        fill(&b[0], &b[0] + 11, 0);
        fill(&visited[0], &visited[0] + 11, 0);
        // 시작 위치
        int idx1 = -1, idx2 = -1;

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                idx1 = j + 1; b[j + 1] = 1;
            } else idx2 = j + 1;
        }
        // 각 구역 수, 해당 선거구의 인구총합
        pair<int, int> red = go(idx1, 1);
        pair<int, int> blue = go(idx2, 0);
        
        // 선거구가 딱 두개라면
        if(red.first + blue.first == n) {
            ret = min(ret, abs(red.second - blue.second));
        }
    }
    cout << ((ret == INT_MAX) ? -1 : ret) << '\n';
    
    return 0;
}
