#include <bits/stdc++.h>
using namespace std;
int n, mx, a[1004];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (double)a[i] / mx * 100;
    }
    cout << sum / n << '\n';
    return 0;
}
