#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s; cin >> n >> s;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int j = 0;
    int min_len = 1e9;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        while(j < n && sum < s) {
            sum += nums[j++];
        }
        if(sum >= s) min_len = min(min_len, j-i);
        sum -= nums[i];
    }
    if(min_len == 1e9) cout << -1 << '\n';
    else cout << min_len << '\n';
    return 0;
}