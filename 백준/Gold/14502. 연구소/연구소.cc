#include <bits/stdc++.h>

using namespace std;

int n, m, ret, cnt, a[10][10], visited[10][10];
vector<pair<int, int>> virusList, wallList;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    int ny, nx;
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(InRange(ny, nx) && a[ny][nx] == 0 && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    
    return;
}

int solve() {
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    
    // 바이러스 퍼뜨리기
    for(pair<int, int> b : virusList) {
        dfs(b.first, b.second);
    }
    
    
    // 안전영역 개수 구하기
    cnt = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0 && visited[i][j] == 0) cnt++;
        }
    }
    
    return cnt;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) wallList.push_back({i, j});
            if(a[i][j] == 2) virusList.push_back({i, j});
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
