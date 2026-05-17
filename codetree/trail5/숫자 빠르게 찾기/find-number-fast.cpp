#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
int get_idx(int target) {
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(nums[mid] == target) {
            return mid + 1;
        }
        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
    }
    if(nums[right] == target) return right + 1;
    return -1;
}

int main() {
    cin >> n >> m;
    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    while(m--) {
        int target; cin >> target;
        cout << get_idx(target) << '\n';
    }
    return 0;
}