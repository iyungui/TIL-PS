#include<bits/stdc++.h>

using namespace std;

int T, ret, c;
string s;
map<pair<string, int>, int> dp;

int go(string s, int cnt) {
    if(cnt == c) {
        return stoi(s);
    }
    if(dp.count({s, cnt})) return dp[{s, cnt}];

    int maxVal = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i + 1; j < s.size(); j++) {
            if(s[i] == s[j]) continue;
            swap(s[i], s[j]);
            int result = go(s, cnt + 1);
            swap(s[j], s[i]);
            maxVal = max(maxVal, result);
        }
    }
    dp[{s, cnt}] = maxVal;
    return maxVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        dp.clear();
        cin >> s >> c;
        ret = go(s, 0);
        cout << "#" << t << " " << ret << '\n';
    }

    return 0;
}