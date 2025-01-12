#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[101][101];
bool visited[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void markOuterAir() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    board[0][0] = 2;  // 2는 외부 공기를 표시

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny] || board[nx][ny] == 1) continue;
            
            board[nx][ny] = 2;
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int meltCheese() {
    int cnt = 0;
    vector<pair<int,int>> melt;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 1) {
                int air = 0;
                for(int k=0; k<4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(board[ni][nj] == 2) air++;
                }
                if(air >= 1) {
                    melt.push_back({i,j});
                    cnt++;
                }
            }
        }
    }

    for(auto p : melt) board[p.first][p.second] = 2;
    return cnt;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    int time = 0;
    int last = 0;

    while(true) {
        markOuterAir();
        int melted = meltCheese();
        if(melted == 0) break;
        last = melted;
        time++;
    }

    cout << time << '\n' << last << '\n';
    return 0;
}
