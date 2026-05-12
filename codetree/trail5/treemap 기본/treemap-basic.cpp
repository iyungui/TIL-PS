#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    map<int, int> mp;
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
        else if(s == "find") {
            int k; cin >> k;
            if(mp.find(k) == mp.end()) cout << "None\n";
            else cout << mp[k] << '\n';
        }
        else if(s == "print_list") {
            if(mp.empty()) {
                cout << "None\n";
                continue;
            }
            for(auto& [k, v] : mp) cout << v << " ";
            cout << '\n';
        }
    }
    return 0;
}