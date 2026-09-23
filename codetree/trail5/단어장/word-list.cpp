#include <bits/stdc++.h>

using namespace std;

int n;
string words[100000];

int main() {
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        mp[words[i]]++;
    }

    // Please write your code here.
    for(const auto& [w, c] : mp) cout << w << " " << c << '\n';
    return 0;
}
