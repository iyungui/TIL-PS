#include<bits/stdc++.h>

using namespace std;

int attack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 9, 3},
    {1, 3, 9}
};

struct A { 
    int a, b, c;
};

int n, mu[3];
int visited[64][64][64];
queue<A> q;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> mu[i];

    q.push({mu[0], mu[1], mu[2]});
    visited[mu[0]][mu[1]][mu[2]] = 1;
    while(q.size()) {
        int x = q.front().a;
        int y = q.front().b;
        int z = q.front().c;
        q.pop();
        
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++) {
            int nx = max(0, x - attack[i][0]);
            int ny = max(0, y - attack[i][1]);
            int nz = max(0, z - attack[i][2]);
            
            if(visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({nx,ny,nz});
        }
    }
    cout << visited[0][0][0] - 1 << '\n';
    return 0;
}