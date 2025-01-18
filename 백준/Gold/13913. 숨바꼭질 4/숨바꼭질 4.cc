#include <bits/stdc++.h>

using namespace std;
#define next aaa
#define prev aaaa
const int MAX = 200000;

int n, m, ret, visited[MAX + 4], prev[MAX + 4];
queue<int> q;
vector<int> v;
int main() {
    cin >> n >> m;
    visited[n] = 1;
    q.push(n);

    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(now == m) {
            ret = visited[m];
            break;
        }
        for(int next : {now - 1, now + 1, now * 2}) {
            if(next >= 0 && next <= MAX && !visited[next]) {
                q.push(next);
                visited[next] = visited[now] + 1;
                prev[next] = now;
            }
        }
    }
    for(int i = m; i != n; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    
    cout << ret - 1 << '\n';
    for(int i : v) cout << i << " ";
    return 0;
}
