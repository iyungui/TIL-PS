#include <bits/stdc++.h>

using namespace std;

int n, k;
unordered_map<int, int> mp;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    vector<pair<int,int>> v;
    for(const auto& [val, cnt] : mp) v.push_back({cnt, val});

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });
    for(int i = 0; i < k; i++) cout << v[i].second << " ";
    return 0;
}
