#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    while(m--) {
        
        int k; cin >> k;
        auto it = lower_bound(nums.begin(), nums.end(), k);
        if(it == nums.end()) cout << -1 << '\n';
        else {
            int idx = it - nums.begin();
            if(nums[idx] == k) cout << idx + 1 << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}