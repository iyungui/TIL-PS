#include <bits/stdc++.h>
using namespace std;

int n, temp, mn = INT_MAX, mx = INT_MIN;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        mn = min(mn, temp);
        mx = max(mx, temp);
    }
    cout << mn << " " << mx << '\n';
    return 0;
}
