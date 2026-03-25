#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[100004], psum[100004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    psum[1] = a[1];
    for(int i = 2; i <= n; i++) {
        psum[i] = psum[i-1] + a[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << psum[b] - psum[a-1] << '\n';
    }
    return 0;
}