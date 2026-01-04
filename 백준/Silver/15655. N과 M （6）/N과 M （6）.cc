#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10], nums[10];

void go(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << nums[a[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = st; i < n; i++) {
        a[k] = i;
        go(k+1, i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n);
    go(0, 0);
    return 0;
}