#include<bits/stdc++.h>

using namespace std;

int T;
string n;
int cnt;
map<pair<string, int>, int> dp;
int ret, result;

int dfs(string num, int remain) {
    if(remain == 0) return stoi(num);
    if(dp.count({num, remain})) {
        return dp[{num, remain}];
    }
    int len = num.size();
    int maxValue = 0;
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            swap(num[i], num[j]);
            result = dfs(num, remain - 1);
            swap(num[j], num[i]);
            maxValue = max(maxValue, result);
        }
    }
    dp[{num, remain}] = maxValue;
    return maxValue;
}

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        dp.clear();
        cin >> n >> cnt;
        ret = dfs(n, cnt);

        cout << "#" << t << " " << ret << '\n';
    }
    return 0;
}