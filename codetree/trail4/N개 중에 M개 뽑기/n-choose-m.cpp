#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[14];

void go(int k, int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++) cout << a[i] << " ";
        cout << '\n';
        return;
    }

    int available = N-k+1;  // 뽑을 수 있는 숫자들(k포함)
    int remain = M-cnt; // 뽑아야할 개수
    if(available < remain) return;

    for(int i = k; i <= N; i++) {
        a[cnt] = i;
        go(i+1, cnt+1);
    }
}

int main() {
    cin >> N >> M;

    // Please write your code here.
    go(1, 0);

    return 0;
}
