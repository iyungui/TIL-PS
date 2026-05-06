#include <bits/stdc++.h>
using namespace std;

int N, ret;
pair<int, int> v[20];
bool visited[1004];

bool can_place(int l, int r) {
    for(int i = l; i <= r; i++) {
        if(visited[i]) return 0;
    }
    return 1;
}

void update_place(int l, int r, bool val) {
    for(int i = l; i <= r; i++) {
        visited[i] = val;
    }
}

void go(int idx, int cnt) {
    if(idx == N) {
        ret = max(ret, cnt);
        return;
    }
    if(can_place(v[idx].first, v[idx].second)) {
        update_place(v[idx].first, v[idx].second, 1);
        go(idx + 1, cnt + 1);
        update_place(v[idx].first, v[idx].second, 0);
    }
    go(idx + 1, cnt);
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    go(0, 0);
    cout << ret << '\n';
    return 0;
}