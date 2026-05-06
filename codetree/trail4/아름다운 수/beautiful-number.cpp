#include <bits/stdc++.h>
using namespace std;

int ret, N;
int a[11];

bool chk() {
    for(int i = 0; i < N; i += a[i]) {
        int st = a[i];
        if(i + st - 1 >= N) return 0;

        for(int j = i; j < i + a[i]; j++) {
            if(a[j] != st) return 0;
        }
    }
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
