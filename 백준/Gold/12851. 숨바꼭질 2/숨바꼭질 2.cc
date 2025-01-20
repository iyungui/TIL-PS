#include <bits/stdc++.h>

#define next aaa
using namespace std;
const int MAX_N = 200000;
int n, k, visited[MAX_N + 4], cnt[MAX_N + 4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    if(n == k) {
        puts("0"); puts("1");
        return 0;
    }
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while(q.size()) {
        int now = q.front(); q.pop();
        if(now == k) break;
        for(int next : {now - 1, now + 1, now * 2}) {
            if(next >= 0 && next <= MAX_N) {
                if(visited[next] == 0) {
                    visited[next] = visited[now] + 1;
                    q.push(next);
                    cnt[next] += cnt[now];
                } else if(visited[next] == visited[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
    return 0;
}
