#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[24];
int chosen[24];

// 뽑은 m개의 숫자를 xor
int calc() {
    int res = chosen[0];
    for(int i = 1; i < m; i++) {
        res ^= chosen[i];
    }
    return res;
}

// 몇번째로 뽑는 숫자인지(cnt), 몇번째인덱스부터 뽑아야 하는지(k)
void go(int cnt, int k) {
    if(cnt == m) {
        ret = max(ret, calc());
        return;
    }
    for(int i = k; i < n; i++) {
        chosen[cnt] = a[i];
        go(cnt+1, i+1);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    go(0, 0);
    cout << ret << '\n';
    return 0;
}