#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    
    vector<int> totalOilByColumn(m, 0);
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    
    for(int c = 0; c < m; c++) {
        for(int r = 0; r < n; r++) {
            // r, c가 석유가 있는 자리이고 방문하지않았다면 bfs
            if(land[r][c] == 1 && !visited[r][c]) {
                visited[r][c] = 1;
                queue<pair<int, int>> q;
                q.push({r, c});
                
                // bfs 하면서, 거쳐간 column 번호저장
                unordered_set<int> col_set;
                
                // 석유의 양 계산
                int cnt = 0;
                
                while(!q.empty()) {
                    auto [y, x] = q.front(); q.pop();
                    cnt++;
                    col_set.insert(x);
                    
                    for(int d = 0; d < 4; d++) {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        
                        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                        
                        if(land[ny][nx] == 0) continue;
                        
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
                
                for(int col : col_set) {
                    totalOilByColumn[col] += cnt;
                }
            }
        }
    }
    
    int answer = 0;
    for(int oil : totalOilByColumn) {
        answer = max(answer, oil);
    }
    return answer;
}