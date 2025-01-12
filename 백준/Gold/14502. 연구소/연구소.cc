#include <bits/stdc++.h>
using namespace std;

int a[10][10], visited[10][10], n, m, ret;
vector<pair<int, int>> wallList, virusList;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(InRange(ny, nx) && a[ny][nx] == 0 && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return;
}

int solve() {
    int cnt = 0;
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for(pair<int, int> b : virusList) {
        dfs(b.first, b.second);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0 && visited[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) wallList.push_back({i, j});
            else if(a[i][j] == 2) virusList.push_back({i, j});
        }
    }
    
    for(int i = 0; i < wallList.size(); i++) {
        for(int j = i + 1; j < wallList.size(); j++) {
            for(int k = j + 1; k < wallList.size(); k++) {
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    
    cout << ret << '\n';
    return 0;
}
