#include<bits/stdc++.h>
using namespace std;

int n, k;

int bfs(int n, int k) {
    if(n == k) return 0;
    vector<int> dist(100004, -1);
    deque<int> dq;

    dq.push_back(n);
    dist[n] = 0;

    while(dq.size()) {
        int cur = dq.front(); dq.pop_front();

        if(cur == k) {
            return dist[k];
        }

        int nxt = cur * 2;
        if(nxt <= 100001 && dist[nxt] == -1) {
            dist[nxt] = dist[cur];
            dq.push_front(nxt);
        }

        nxt = cur - 1;
        if(nxt >= 0 && dist[nxt] == -1) {
            dist[nxt] = dist[cur] + 1;
            dq.push_back(nxt);
        }
        nxt = cur + 1;
        if(nxt <= 100001 && dist[nxt] == -1) {
            dist[nxt] = dist[cur] + 1;
            dq.push_back(nxt);
        }
    }
    return dist[k];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cout << bfs(n, k) << '\n';
    return 0;
}