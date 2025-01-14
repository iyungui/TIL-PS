#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int a[54][54];
int visited[54][54];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> union_pos;

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

void dfs(int y, int x, vector<pair<int, int>>& union_pos) {
    visited[y][x] = 1;
    union_pos.push_back({y, x});
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(InRange(ny, nx) && !visited[ny][nx]) {
            int diff = abs(a[y][x] - a[ny][nx]);
            if(diff >= l && diff <= r) {
                dfs(ny, nx, union_pos);
            }
        }
    }
}

bool move() {
    memset(visited, 0, sizeof(visited));
    bool moved = false;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                union_pos.clear();
                dfs(i, j, union_pos);
                
                if(union_pos.size() > 1) {
                    moved = true;
                    int sum = 0;
                    for(auto& p : union_pos) {
                        sum += a[p.first][p.second];
                    }
                    
                    int avg = sum / union_pos.size();
                    for(auto& p : union_pos) {
                        a[p.first][p.second] = avg;
                    }
                }
            }
        }
    }
    return moved;
}

int main() {
    cin >> n >> l >> r;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    int days = 0;
    while(move()) {
        days++;
    }
    
    cout << days << '\n';
    return 0;
}
