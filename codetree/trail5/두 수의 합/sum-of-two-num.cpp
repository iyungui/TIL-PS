#include <bits/stdc++.h>
using namespace std;


int a[100004], cnt;
unordered_map<int, int> mp;
int main() {
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++) {
        int target = k - a[i];
        if(mp.find(target) != mp.end()) cnt += mp[target];
        mp[a[i]]++;
    }

    cout << cnt << '\n';

    /*
    a
    4 6 5 3 7
    target
    5 3 4 6 2
    cnt
    0 0 1 2 2
    */
    return 0;
}