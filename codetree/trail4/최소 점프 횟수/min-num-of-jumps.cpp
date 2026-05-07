#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> nums;
int ret = 14;

void go(int cur, int pos) {
    if(pos >= N-1) {
        ret = min(ret, cur);
        return;
    }
    for(int i = 1; i <= nums[pos]; i++) {
        go(cur + 1, pos + i);
    }
}

int main() {
    cin >> N;
    nums.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    go(0, 0);
    if(ret == 14) cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}