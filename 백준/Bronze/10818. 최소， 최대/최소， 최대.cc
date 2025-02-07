#include <bits/stdc++.h>
using namespace std;

int n, a[1000004], mn = INT_MAX, mx = INT_MIN;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    cout << mn << " " << mx << '\n';
    return 0;
}