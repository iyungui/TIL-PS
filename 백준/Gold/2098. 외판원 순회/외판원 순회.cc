#include<bits/stdc++.h>
using namespace std;

// 현재 i번째 방문, 지금까지 visited 방문한 상태.에서 나머지 모든 도시 방문하면서 다시 시작점까지 돌아오는 가장 적은 비용 
int d[16][1 << 16];
int n;
const int INF = 1e9;
int w[20][20];
int dfs(int cur, int visited) {
    // 다 방문한 경우
    if(visited == (1 << n) - 1) {
        // 다시 시작점으로 돌아오는 길이 있으면 1
        // 길이 없으면 0이므로, INF 반환.
        return w[cur][0] ? w[cur][0] : INF;
    }
    // 이미 계산된 경로인경우
    int &ret = d[cur][visited];
    if(~ret) return ret;
    ret = INF;  // 방문하지 않은 상태 -> 최댓값부터.
    // cur에서 나머지 도시 중 이동
    for(int i = 0; i < n; i++) {
        // 이미 방문했거나 길이 없는 경우는 가지 않음
        if(visited & (1 << i)) continue;
        if(w[cur][i] == 0) continue;

        // cur에서 i번째 도시로 방문하는 경우와 비교
        ret = min(ret, w[cur][i] + dfs(i, visited | (1 << i)));
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << dfs(0, 1) << '\n';
    return 0;
}