#include <bits/stdc++.h>
using namespace std;

char a[1004][1004];
int n, m, sx, sy, ret, y, x;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int fire_check[1004][1004], person_check[1004][1004];
queue<pair<int, int>> q;

bool InRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INT_MAX);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            
            if(a[i][j] == 'F') {
                fire_check[i][j] = 1; q.push({i, j});
            } else if(a[i][j] == 'J') {
                sy = i; sx = j;
            }
        }
    }
    
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(InRange(ny, nx) && a[ny][nx] != '#' && fire_check[ny][nx] == INT_MAX) {
                fire_check[ny][nx] = fire_check[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    
    person_check[sy][sx] = 1;
    q.push({sy, sx});
    
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        
        if(x == m - 1 || x == 0 || y == 0 || y == n - 1) {
            ret = person_check[y][x];
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(InRange(ny, nx) && a[ny][nx] != '#' && !person_check[ny][nx] && (fire_check[ny][nx] > person_check[y][x] + 1)) {
                person_check[ny][nx] = person_check[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    
    if(ret != 0) cout << ret << '\n';
    else cout << "IMPOSSIBLE \n";

    return 0;
}
