#include<bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int M, N;
int a[504][504];
int d[504][504];    // d[y][x] = (y,x)지점에서 목표지점까지 갈 수 있는 모든 경로의 수

int dfs(int y, int x) {
    if(y == M - 1 && x == N - 1) return 1;
    // 이미 계산된 경우
    if(d[y][x] != -1) return d[y][x];

    // 해당 지점을 처음 방문하므로 -1에서 0으로
    d[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if(a[ny][nx] < a[y][x]) {
            d[y][x] += dfs(ny,nx);
        }
    }
    return d[y][x];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    // -1이면 아직 방문하지 않았음을
    // 0이면 이제 막 방문했음을. (혹은 목적지까지 가는 경로의 수가 0일 때)
    memset(d, -1, sizeof(d));
    cout << dfs(0,0) << '\n';
    return 0;
}