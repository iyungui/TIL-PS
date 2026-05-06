#include <bits/stdc++.h>
using namespace std;

// idx

int K, N;
int ans[10];

void go(int idx) {
    if(idx == N) {
        for(int i = 0; i < N; i++) cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= K; i++) {
        ans[idx] = i;
        go(idx + 1);
    }
}
int main() {
    // Please write your code here.
    cin >> K >> N;
    go(0);
    return 0;
}