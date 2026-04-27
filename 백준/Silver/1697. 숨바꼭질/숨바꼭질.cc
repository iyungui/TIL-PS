#include<bits/stdc++.h>

using namespace std;

int n, k;
int pos, t;
int dist[100004];
queue<int> q;    // position

int bfs() {
    while(!q.empty()) {
        int pos = q.front(); q.pop();
        for(int nxt : {pos-1, pos+1, pos*2}) {
            // 다음위치가 동생 위치인 경우
            if(nxt == k) return dist[pos] + 1;

            // 수빈이의 다음 위치가 범위 안에 있고, 미방문 위치인 경우
            if(nxt >= 0 && nxt <= 100000 && dist[nxt] == -1) {
                dist[nxt] = dist[pos] + 1;
                q.push(nxt);
            }
        }
    }
    return -1;  // 동생을 보지 못하는 경우
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    // 동생이 수빈과 동일한 위치 혹은 뒤에 있는 경우. 
    if(n >= k) { cout << n - k << '\n'; return 0; }

    // 수빈이의 위치 n
    memset(dist, -1, sizeof(dist));
    dist[n] = 0;
    q.push(n);
    
    cout << bfs() << '\n';
    return 0;
}