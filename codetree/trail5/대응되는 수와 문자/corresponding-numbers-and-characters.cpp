#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;
    unordered_map<string, int> mp;
    unordered_map<int, string> mp2;
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        mp[s] = i;
        mp2[i] = s;
    }
    while(m--) {
        string c; cin >> c;
        if(isdigit(c[0])) cout << mp2[stoi(c)] << '\n';
        else cout << mp[c] << '\n';
    }
    return 0;
}