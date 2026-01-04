#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int used[20], used2[40], used3[40];

void go(int k) {
    if(k == n) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(used[i] || used2[k+i] || used3[k-i+n-1]) continue;
        used[i] = 1;
        used2[k+i] = 1;
        used3[k-i+n-1] = 1;
        go(k+1);
        used[i] = 0;
        used2[k+i] = 0;
        used3[k-i+n-1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    go(0);
    cout << cnt << '\n';
    return 0;
}