#include<bits/stdc++.h>
using namespace std;

int a[24], n, s, ret;

void go(int idx, int sum) {
    if(idx == n) {
        if(sum == s) ret++;
        return;
    }
    go(idx + 1, sum + a[idx]);
    go(idx + 1, sum);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    go(0, 0);
    if(s == 0) ret--;
    cout << ret << '\n';
    return 0;
}