#include <bits/stdc++.h>
using namespace std;

int n, ret = 1e9;
int a[13][13];
bool visited[13];
int visited_cnt;
void go(int prev, int cnt, int cost) {
    if(cost >= ret) return;
    if(cnt == n) {
        if(a[prev][0] != 0) ret = min(ret, cost + a[prev][0]);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        if(a[prev][i] == 0) continue;
        visited[i] = 1;
        go(i, cnt+1, cost + a[prev][i]);
        visited[i] = 0;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    visited[0] = 1;
    go(0, 1, 0);
    cout << ret << '\n';
    return 0;
}