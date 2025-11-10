#include<bits/stdc++.h>
using namespace std;

map<pair<string, int>, int> dp;

int T, cnt;
string s;

int go(string s, int c) {
    if(c == cnt) return stoi(s);
    if(dp.count({s, c})) return dp[{s, c}];
    int maxVal = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i + 1; j < s.size(); j++) {
            if(s[i] == s[j]) continue;
            swap(s[i], s[j]);
            maxVal = max(maxVal, go(s, c + 1));
            swap(s[j], s[i]);
        }
    }
    return dp[{s, c}] = maxVal;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    cin >> T;

    for(int t = 1; t <= T; t++) {
        dp.clear();
        cin >> s >> cnt;
        int ret = go(s, 0);
        cout << "#" << t << " " << ret << '\n';
    }
    return 0;
}