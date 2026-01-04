#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10], nums[10], isused[10];

void go(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << nums[a[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!isused[i]) {
            isused[i] = 1;
            a[k] = i;
            go(k+1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n);
    go(0);
    return 0;
}