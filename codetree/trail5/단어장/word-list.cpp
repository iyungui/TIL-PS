#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
int n;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s]++;
    }
    for(auto& [str, cnt] : mp) cout << str << " " << cnt << '\n';
    return 0;
}