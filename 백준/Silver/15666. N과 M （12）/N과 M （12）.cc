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
    if(k) st = a[k-1];
    for(int i = st; i < n; i++) {
        a[k] = i;
        go(k+1);
    }
}

vector<bool> chk(10002);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int idx = 0;
    while(n--) {
        cin >> nums[idx];
        if(chk[nums[idx]]) continue;
        chk[nums[idx]] = 1;
        idx++;
    }
    n = idx;
    sort(nums, nums+n);
    go(0);
    return 0;
}