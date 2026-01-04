#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10];

void go(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = st; i <= n; i++) {
        a[k] = i;
        go(k + 1, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    go(0, 1);
    return 0;
}