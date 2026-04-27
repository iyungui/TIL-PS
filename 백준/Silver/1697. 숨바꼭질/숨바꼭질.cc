#include<bits/stdc++.h>

using namespace std;

int n, k, ret;
int pos, t;
bool visited[100004];
queue<pair<int, int>> q;    // position, time

int bfs() {
    while(!q.empty()) {
        tie(pos, t) = q.front(); q.pop();
        vector<int> next_position = {pos-1, pos+1, pos*2};

        for(int nxt : next_position) {
            // 다음위치가 동생 위치인 경우
            if(nxt == k) return t + 1;

            // 수빈이의 다음 위치가 범위 안에 있고,
            // 미방문 위치인 경우
            if(nxt >= 0 && nxt <= 100000 && !visited[nxt]) {
                visited[nxt] = 1;
                q.push({nxt, t + 1});
            }
        }
    }
    return -1;  // 동생을 보지 못하는 경우
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    // 동생이 수빈과 동일한 위치 혹은 뒤에 있는 경우. 
    if(n >= k) {
        cout << n - k << '\n';
        return 0;
    }

    // 수빈이의 위치 n에 0초에 도달
    q.push({n, 0});
    visited[n] = 1;
    ret = bfs();

    cout << ret << '\n';
    return 0;
}