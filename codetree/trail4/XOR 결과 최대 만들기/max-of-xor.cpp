#include <bits/stdc++.h>

using namespace std;

int n, m;
int A[20];
int ret;

void go(int cnt, int k, int val) {
    if(cnt == m) {
        ret = max(ret, val);
        return;
    }
    if(n-k < m-cnt) return;
    
    for(int i = k; i < n; i++) {
        go(cnt+1, i+1, val ^ A[i]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    go(0, 0, 0);
    cout << ret << '\n';
    return 0;
}