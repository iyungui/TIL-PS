#include<bits/stdc++.h>
using namespace std;

int n, L, R;
int day;
int A[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L >> R;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    while(1) {
        vector<vector<bool>> visited(n+1, vector<bool>(n+1, 0));
        bool move = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) continue; // 이미 방문했다면 스킵
                
                queue<pair<int, int>> q;
                visited[i][j] = 1;
                int num = A[i][j];  // 연합의 인구수
                vector<pair<int, int>> v;
                v.push_back({i, j});
                q.push({i, j});
                
                while(q.size()) {
                    int y, x;
                    tie(y, x) = q.front(); q.pop();
                    for(int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(visited[ny][nx]) continue;
                        int diff = abs(A[y][x] - A[ny][nx]);
                        if(diff >= L && diff <= R) {
                            num += A[ny][nx];
                            v.push_back({ny, nx});
                            visited[ny][nx] = 1;
                            q.push({ny, nx});
                        }
                    }
                }
                // 인구이동이 일어나는 경우
                if(v.size() >= 2) {
                    move = true;
                    int tmp = num / (int)v.size();
                    for(auto& p : v) {
                        A[p.first][p.second] = tmp;
                    }
                }
            }
        }

        // 인구 이동이 일어나지 않음
        if(!move) break;
        day++;
    }

    cout << day << '\n';
    return 0;   
}