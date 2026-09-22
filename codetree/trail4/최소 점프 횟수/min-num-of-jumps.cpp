#include <bits/stdc++.h>

using namespace std;

int n;
int num[10];
int ret = 1e9;

// 4^10
void go(int cur_idx, int jump_cnt) {
    if(cur_idx == n - 1) {
        ret = min(ret, jump_cnt);
        return;
    }
    for(int i = 1; i <= num[cur_idx]; i++) {
        int nxt = cur_idx + i;
        if(nxt < n) go(nxt, jump_cnt + 1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    go(0, 0);

    if(ret == 1e9) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}
