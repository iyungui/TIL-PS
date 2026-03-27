#include<bits/stdc++.h>
using namespace std;

string str = "antic";
int learned;
int words[55];
int max_cnt;
int n, k;

void dfs(int idx, int cnt) {
    if(cnt == k - 5) {
        int t = 0;
        for(int i = 0; i < n; i++) {
            if((words[i] & learned) == words[i]) t++;
        }
        if(t == n) {
            cout << n << '\n';
            exit(0);
        }

        max_cnt = max(max_cnt, t);
        return;
    }

    for(int i = idx; i < 26; i++) {
        if(learned & (1 << i)) continue;

        learned |= (1 << i);
        dfs(i+1, cnt+1);
        learned &= ~(1 << i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(char c : s) words[i] |= (1 << (c - 'a'));
    }
    if(k < 5) {
        cout << 0 << '\n';
        return 0;
    }
    if(k == 26) {
        cout << n << '\n';
        return 0;
    }

    for(char c : str) learned |= (1 << (c - 'a'));

    dfs(0, 0);

    cout << max_cnt << '\n';
    return 0;
}