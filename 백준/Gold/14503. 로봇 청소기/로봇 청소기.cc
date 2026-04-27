#include<bits/stdc++.h>

using namespace std;

int n, m;
int r, c, d;
int board[54][54];
int cnt;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            // 0: 청소해야할 빈 칸
            // 1: 벽
        }
    }

    while(1) {
        // 현재 칸 청소
        if(board[r][c] == 0) {
            board[r][c] = 2;
            cnt++;
        }
        
        // 주변 4칸 탐색
        bool flag = 0;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 배열의 범위를 벗어난 경우
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(board[nr][nc] == 0) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            for(int i = 0; i < 4; i++) {
                d = (d+3) % 4;
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(board[nr][nc] == 0) {
                    r = nr; c = nc;
                    break;
                }
            }
            continue;
        }
        // 바라보는 방향을 유지한 채로 한 칸 후진 시도
        int tmp = (d + 2) % 4;
        int nr = r + dr[tmp];
        int nc = c + dc[tmp];
        
        // 후진할 수 없는 경우 작동을 멈춤
        if(nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] == 1) break;
        // 후진
        r = nr; c = nc;
    }
    cout << cnt << '\n';
    
    return 0;
}