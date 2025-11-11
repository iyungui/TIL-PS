#include<bits/stdc++.h>

using namespace std;

const int TC = 10;
int n;
vector<string> a;

int solve() {
    int ret = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j <= 8 - n; j++) {
            string s = a[i].substr(j, n);
            string temp = s;
            reverse(s.begin(), s.end());
            if(s == temp) ret++;
        }
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j <= 8 - n; j++) {
            string s = "";
            for(int k = 0; k < n; k++) {
                s += a[j + k][i];
            }
            string temp = s;
            reverse(s.begin(), s.end());
            if(s == temp) ret++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for(int t = 1; t <= TC; t++) {
        cin >> n;
        a.clear();
        for(int i = 0; i < 8; i++) {
            string s; 
            cin >> s;
            a.push_back(s);
        }

        int cnt = solve();

        cout << "#" << t << " " << cnt << '\n';
    }
    return 0;
}