#include <bits/stdc++.h>

using namespace std;

int a[54];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, p; 
    cin >> n >> k >> p;
    for(int i = 0; i < n; i++) cin >> a[i];

    int rank = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > k) rank++;
        else if(a[i] == k) cnt++;
        else if(a[i] < k) break;
    }
    if(rank + cnt >= p) cout << -1 << '\n';
    else cout << rank + 1 << '\n';
    return 0;
}