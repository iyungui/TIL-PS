#include<bits/stdc++.h>

using namespace std;
int n, m, a[10], used[10];
void go(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) cout << a[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            used[i] = 1;
            a[k] = i;
            go(k + 1);
            used[i] = 0;
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    go(0);
    return 0;
}