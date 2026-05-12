#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, int> mp;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if(mp.find(x) == mp.end()) mp[x] = y;
        else if(mp[x] > y) mp[x] = y;
    }
    long long sum = 0;
    for(auto& [_, y] : mp) sum += y;
    cout << sum << '\n';
    return 0;
}