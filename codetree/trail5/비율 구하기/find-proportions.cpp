#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> mp;
string words[10004];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        mp[words[i]]++;
    }

    // Please write your code here.
    for(const auto& [val, cnt] : mp) {
        double r = (double)cnt / n * 100;
        cout << fixed << setprecision(4);
        cout << val << " " << r << '\n';
    }

    return 0;
}
