#include<bits/stdc++.h>
using namespace std;

int k;
int a[15], b[6];

void go(int cnt, int st) {
    if(cnt == 6) {
        for(int i = 0; i < 6; i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = st; i < k; i++) {
        b[cnt] = a[i];
        go(cnt+1, i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1) {
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) {
            cin >> a[i];
        }
        go(0, 0);
        cout << '\n';
    }
    return 0;
}