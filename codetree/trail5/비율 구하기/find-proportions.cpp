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
    for(auto& [str, cnt] : mp) {
        double r = (double)cnt / n * 100;
        cout << fixed << setprecision(4);
        cout << str << " " << r << '\n';
    }
    return 0;
}