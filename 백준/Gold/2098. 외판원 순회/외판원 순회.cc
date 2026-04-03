#include<bits/stdc++.h>
using namespace std;

int d[16][1 << 16]; // d[i][visited]: 0번째 도시에서 출발하여 현재까지 visited방문하였고 현재는 i번째를 방문하는 중, 나머지 모든 도시를 다 순회한 뒤 0번째로 다시 돌아오기 까지의 최소비용
int dist[16][16];
int n;
const int INF = 1e9;

int go(int cur, int visited) {
    // 모든 도시를 다 방문한 경우
    if(visited == (1 << n) - 1) {
        return dist[cur][0] ? dist[cur][0] : INF;
    }
    // 이미 계산된 경로인 경우
    int &ret = d[cur][visited];
    if(ret != -1) return ret;

    // 최대값으로 초기화하고 다음 도시 방문 시작
    ret = INF;
    // cur에서 갈 수 있는 모든 도시를 탐색
    for(int i = 0; i < n; i++) {
        // 이미 방문한 도시인 경우
        if(visited & (1 << i)) continue;
        // 길이 없는 경우
        if(dist[cur][i] == 0) continue;
        ret = min(ret, dist[cur][i] + go(i, visited | (1 << i)));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    memset(d, -1, sizeof(d));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    // 0번 도시부터 방문 -> 나머지 모든 도시 방문 -> 다시 0번 도시까지 오는데 최소비용
    cout << go(0, 1) << '\n'; 

    return 0;
}