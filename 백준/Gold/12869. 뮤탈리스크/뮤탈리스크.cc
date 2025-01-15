#include <bits/stdc++.h>
using namespace std;

int n;
int a[3], visited[64][64][64];  // 해당 체력 방문한 적 있는가?

vector<int> b = {1, 3, 9};
vector<vector<int>> v;

struct scv {
    int x, y, z;
};

void bfs(int x, int y, int z) {
    int cnt = 0;
    queue<scv> q;
    q.push({x, y, z});
    
    visited[x][y][z] = 1;
    
    while(q.size()) {
        x = q.front().x;
        y = q.front().y;
        z = q.front().z;
        q.pop();
        
        if(x == 0 && y == 0 && z == 0) {
            cout << visited[x][y][z] - 1 << '\n';
            return;
        }
        
        for(int i = 0; i < v.size(); i++) {
            int nx = max(0, x - v[i][0]);
            int ny = max(0, y - v[i][1]);
            int nz = max(0, z - v[i][2]);
            if(visited[nx][ny][nz]) continue;
            
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }
    
    return;
}

int main() {
    
    do {
        v.push_back(b);
    } while(next_permutation(b.begin(), b.end()));
    
    cin >> n;
    
    memset(a, 0, sizeof(a));
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    bfs(a[0], a[1], a[2]);
    
    return 0;
}
