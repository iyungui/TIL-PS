#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    while(m--) {
        int k; cin >> k;
        auto it = lower_bound(nums.begin(), nums.end(), k);

        if(it == nums.end() || *it != k) cout << -1 << '\n';
        else cout << it - nums.begin() + 1 << '\n';
    }
    return 0;
}