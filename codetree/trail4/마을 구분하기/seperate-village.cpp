#include <bits/stdc++.h>
using namespace std;

// 총 마을의 개수, 
// [같은 마을에 있는 사람의 수를 오름차순]

int n;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int board[30][30], visited[30][30];
vector<int> towns;
int cnt;

int dfs(int y, int x) {
    int ret = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if(board[ny][nx] == 1) {
            visited[ny][nx] = 1;
            ret += dfs(ny, nx);
        }
    }

    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = 1;
                cnt++;
                towns.push_back(dfs(i, j));
            }
        }
    }
    sort(towns.begin(), towns.end());
    cout << cnt << '\n';
    for(int i : towns) cout << i << '\n';
    return 0;
}