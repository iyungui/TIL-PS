#include<bits/stdc++.h>
using namespace std;

int n, m, C;
int d[1 << 13][11][21];
int w[11];
// 현재 mask의 보석을 담았고(비트마스킹), bag_idx번째 가방에, remain - x의 보석을 담을차례
int go(int mask, int bag_idx, int remain) {
    // 모든 가방 혹은 모든 보석 다 본 경우
    if(bag_idx == m || mask == (1 << n) - 1) {
        return 0;
    }
    // 이미 계산된 상태인경우
    int &ret = d[mask][bag_idx][remain];
    if(~ret) return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i)) continue;
        if(remain >= w[i]) {
            ret = max(ret, go(mask | (1 << i), bag_idx, remain - w[i]) + 1);
        }
    }
    ret = max(ret, go(mask, bag_idx+1, C));
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> C;
    for(int i = 0; i < n; i++) cin >> w[i];
    memset(d, -1, sizeof(d));
    cout << go(0, 0, C);
    return 0;
}