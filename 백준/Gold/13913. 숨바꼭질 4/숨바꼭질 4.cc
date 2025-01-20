#include <bits/stdc++.h>

#define next aaa
#define prev aaaa
using namespace std;
const int MAX_N = 200000;
int n, k, visited[MAX_N + 4];
int prev[MAX_N + 4];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(q.size()) {
        int now = q.front(); q.pop();
        if(now == k) break;
        for(int next : {now - 1, now + 1, now * 2}) {
            if(next >= 0 && next <= MAX_N) {
                if(visited[next] == 0) {
                    visited[next] = visited[now] + 1;
                    q.push(next);
                    prev[next] = now;
                }
            }
        }
    }
    for(int i = k; i != n; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    cout << visited[k] - 1 << '\n';
    for(int i : v) cout << i << " ";
    return 0;
}
