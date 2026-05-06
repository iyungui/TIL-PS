#include <bits/stdc++.h>
using namespace std;

int ret, N;
int a[11];

bool chk() {
    int prev = a[0];
    int cnt = 1;

    for(int i = 1; i < N; i++) {
        if(a[i] == prev) {
            cnt++;
        }
        else {
            if(cnt % prev != 0) return 0;
            else cnt = 1;
        }
        prev = a[i];
    }
    if(cnt % prev != 0) return 0;
    return 1;
}

void go(int idx) {
    if(idx == N) {
        if(chk()) ret++;
        return;
    }
    for(int i = 1; i <= 4; i++) {
        a[idx] = i;
        go(idx + 1);
    }
}

int main() {
    // Please write your code here.
    cin >> N;
    go(0);
    cout << ret << '\n';
    return 0;
}
