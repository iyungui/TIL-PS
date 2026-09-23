#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<int, string> mp;
unordered_map<string, int> mp2;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        mp[i] = s;
        mp2[s] = i;
    }

    for (int i = 0; i < m; i++) {
        string q; cin >> q;
        if(isdigit(q[0])) cout << mp[stoi(q)] << '\n';
        else cout << mp2[q] << '\n';
    }

    // Please write your code here.

    return 0;
}
