#include <bits/stdc++.h>

using namespace std;
const int max_n = 200000;
int n, k, visited[max_n + 4], cnt[max_n + 4];
int main() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(x == k) break;
        for(int next : {x - 1, x + 1, x * 2}) {
            if(next < max_n && next >= 0) {
                if(visited[next] == 0) {
                    visited[next] = visited[x] + 1;
                    q.push(next);
                    cnt[next] += cnt[x];
                } else {
                    if(visited[next] == visited[x] + 1) {
                        cnt[next] += cnt[x];
                    }
                }
            }
        }
    }
    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
    return 0;
}
