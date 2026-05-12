#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> mp;
int ret;
int main() {
    cin >> n; 
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        ret = max(ret, ++mp[s]);
    }
    cout << ret << '\n';
    return 0;
}