#include<bits/stdc++.h>
using namespace std;

int N, L, R;
int a[54][54];

bool visited[54][54];
int day;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

bool bfs(int sy, int sx) {
    visited[sy][sx] = 1;

    int num = a[sy][sx];  // 연합의 인구수
    queue<pair<int, int>> q;    // bfs 탐색을 위한 큐
    vector<pair<int, int>> group;   // 연합 그룹

    q.push({sy, sx});
    group.push_back({sy, sx});

    while(!q.empty()) {
        int y, x;

        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 배열 범위 벗어나거나 이미 방문한 경우는 제외
            if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;

            // 연합 조건 체크
            int diff = abs(a[y][x] - a[ny][nx]);
            if(diff >= L && diff <= R) {
                num += a[ny][nx];
                group.push_back({ny, nx});
                visited[ny][nx] = 1;    // 실제로 연합을 이루는 경우에만 방문처리
                q.push({ny, nx});
            }
        }
    }

    // 인구 이동이 일어나는 경우
    if((int)group.size() >= 2) {
        int tmp = num / (int)group.size();
        for(auto& p : group) {
            a[p.first][p.second] = tmp;
        }
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    while(1) {
        memset(visited, 0, sizeof(visited)); // 인구 이동 시작 전 방문배열 초기화
        bool moved = false; // 인구이동이 한번이라도 발생했는지 여부
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                // 이미 방문한 나라인 경우 스킵
                if(visited[i][j]) continue;
                if(bfs(i, j)) moved = true;
            }
        }

        // 인구이동이 일어나지 않는 경우
        if(!moved) break;
        day++;
    }

    cout << day << '\n';

    return 0;
}