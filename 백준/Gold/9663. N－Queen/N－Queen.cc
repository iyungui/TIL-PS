#include<bits/stdc++.h>
using namespace std;

int n, ret;
int isused[40], isused2[40], isused3[40];

void go(int k) {
    if(k == n) {
        ret++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(isused[i] || isused2[i+k] || isused3[i-k+n-1]) continue;
        isused[i] = 1;
        isused2[i+k] = 1;
        isused3[i-k+n-1] = 1;
        go(k+1);
        isused[i] = 0;
        isused2[i+k] = 0;
        isused3[i-k+n-1] = 0;
    }
}

int main() {
    cin >> n;
    go(0);
    cout << ret << '\n';
    return 0;
}