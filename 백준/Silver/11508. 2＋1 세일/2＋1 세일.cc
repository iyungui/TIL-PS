#include <bits/stdc++.h>

using namespace std;

int n;
int a[100004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    long long ret = 0;
    for(int i = 0; i < n; i++) {
        if((i+1) % 3 == 0) continue;
        ret += a[i];
    }
    cout << ret << '\n';
    return 0;
}