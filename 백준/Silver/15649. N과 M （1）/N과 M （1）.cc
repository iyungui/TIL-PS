#include<bits/stdc++.h>
using namespace std;

int n, m, isused[10], a[10];

void go(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!isused[i]) {
            isused[i] = 1;
            a[k] = i;
            go(k+1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    go(0);
    return 0;
}