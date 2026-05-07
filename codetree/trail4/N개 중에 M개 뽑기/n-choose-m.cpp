#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[14];

void go(int st, int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++) cout << a[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = st; i <= N; i++) {
        a[cnt] = i;
        go(i + 1, cnt + 1);
    }
}

int main() {
    cin >> N >> M;
    go(1,0);
    return 0;
}