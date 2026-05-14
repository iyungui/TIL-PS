#include <bits/stdc++.h>
using namespace std;

int n, q;
int main() {
    cin >> n >> q;
    vector<int> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i];
    }
    sort(points.begin(), points.end());
    while(q--) {
        int a, b; cin >> a >> b;
        auto L = lower_bound(points.begin(), points.end(), a);
        auto R = upper_bound(points.begin(), points.end(), b);
        cout << R - L << '\n';
    }
    return 0;
}