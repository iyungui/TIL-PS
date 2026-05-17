#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    while(m--) {
        int t; cin >> t;
        auto u = upper_bound(nums.begin(), nums.end(), t);
        auto d = lower_bound(nums.begin(), nums.end(), t);
        cout << u - d << '\n';
    }
    return 0;
}