#include<bits/stdc++.h>

using namespace std;

int n, m, nums[10], a[10];

void go(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << nums[a[i]] << " ";
        }
        cout << '\n';
        return;
    }

    int st = 0;
    int prev = -1;
    if(k) st = a[k-1] + 1;
    for(int i = st; i < n; i++) {
        if(prev == nums[i]) continue;
        prev = nums[i];
        a[k] = i;
        go(k+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums+n);
    go(0);
    return 0;
}