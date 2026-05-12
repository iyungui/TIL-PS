#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    unordered_map<int, int> mp;

    while(n--) {
        string s; cin >> s;
        if(s == "add") {
            int k, v; cin >> k >> v;
            mp[k] = v;
        }
        else if(s == "remove") {
            int k; cin >> k;
            mp.erase(k);
        }
        else {
            int k; cin >> k;
            if(mp.find(k) == mp.end()) cout << "None\n";
            else cout << mp[k] << '\n';
        }
    }
    return 0;
}