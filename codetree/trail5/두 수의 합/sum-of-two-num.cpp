#include <bits/stdc++.h>

using namespace std;

int n, k, ret;
unordered_map<int,int> mp;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int t = k-x;
        if(mp.find(t) != mp.end()) ret += mp[t];
        mp[x]++;
    }
    cout << ret << '\n';
    return 0;
}
