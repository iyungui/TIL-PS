#include<bits/stdc++.h>

using namespace std;

int T, n, k, cnt, a[24];

void go(int i, int sum) {
    if(sum == k) {
        cnt++;
        return;
    }
    if(i == n) return;
    go(i + 1, sum);
    if(sum + a[i] <= k) go(i + 1, sum + a[i]);
}

int main() {
    cin >> T;

    for(int t = 1; t <= T; t++) {
        cnt = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        go(0, 0);

        cout << "#" << t << " " << cnt << '\n';
    }
    return 0;
}