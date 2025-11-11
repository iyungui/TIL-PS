#include<bits/stdc++.h>

using namespace std;

int T, n, k, a[24];
int ret;

void go(int idx, int sum) {
    if(idx == n) {
        if(sum == k) ret++;
        return;
    }
    go(idx + 1, sum + a[idx]);
    go(idx + 1, sum);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;

    for(int t = 1; t <= T; t++) {
        memset(a, 0, sizeof(a));
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        ret = 0;
        go(0, 0);
        cout << "#" << t << " " << ret << '\n';
    }

    return 0;
}