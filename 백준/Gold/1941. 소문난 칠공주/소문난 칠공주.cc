#include<bits/stdc++.h>
using namespace std;

const int n = 5;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int ret;
char arr[7][7];
bool selected[30];
bool visited[5][5];
string str;
int ny, nx, y, x, sy, sx;

bool bfs() {
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    
    int st = -1;
    for(int i = 0; i < 25; i++) {
        if(selected[i]) {
            st = i;
            break;
        }
    }

    sy = st / 5;
    sx = st % 5;

    visited[sy][sx] = 1;
    q.push({sy, sx});

    int connectedCnt = 1;

    while(q.size()) {
        tie(y, x) = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
            int nxt = ny * 5 + nx;
            if(selected[nxt]) {
                visited[ny][nx] = 1;
                q.push({ny,nx});
                connectedCnt++;
            }

        }
    }
    return connectedCnt == 7;
}

void dfs(int idx, int k, int sCnt) {
    if(k == 7) {
        if(sCnt >= 4 && bfs()) ret++;
        return;
    }
    if(idx == 25) return;
    // idx번째 학생을 선택하는 경우(해당 학생이 'S'라면 sCnt++)
    selected[idx] = 1;
    dfs(idx+1, k+1, sCnt + (arr[idx / 5][idx % 5] == 'S'));
    // 원복
    selected[idx] = 0;

    // idx번째 학생을 선택하지 않는경우
    dfs(idx+1, k, sCnt);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < n; j++) {
            arr[i][j] = str[j];
        }
    }
    dfs(0, 0, 0);
    cout << ret << '\n';
    return 0;
}