#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10];

void dfs(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    int st = 1;
    if(k != 0) st = a[k-1] + 1;
    for(int i = st; i <= n; i++) {
        a[k] = i;
        dfs(k + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    dfs(0);
    return 0;
}