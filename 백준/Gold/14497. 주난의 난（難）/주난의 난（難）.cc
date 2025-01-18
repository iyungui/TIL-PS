#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char a[301][301];
int visited[301][301];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, y1, x1, y2, x2;
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }

    queue<pair<int,int>> q;
    q.push({y1, x1});
    visited[y1][x1] = 1;
    
    int cnt = 0;
    while(a[y2][x2] != '0'){
        cnt++;
        queue<pair<int,int>> temp;
        
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0';
                    temp.push({ny, nx});
                }
                else q.push({ny, nx});
            }
        }
        q = temp;
    }
    
    cout << visited[y2][x2] << '\n';
    return 0;
}
