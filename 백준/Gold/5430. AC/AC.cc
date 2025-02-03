#include <bits/stdc++.h>

using namespace std;

int t, n;
string p, s;

int main() {
    cin >> t;
    while(t--) {
        cin >> p >> n >> s;
        deque<int> d;
        int cur = 0;
        for(char c : s) {
            if(c == ']' || c == '[') continue;
            else if(c >= '0' && c <= '9') {
                cur = cur * 10 + c - '0';
            } else {
                if(cur > 0) d.push_back(cur);
                cur = 0;
            }
        }
        if(cur > 0) d.push_back(cur);
        
        bool error = false, rev = false;
        
        for(char a : p) {
            if(a == 'R') {
                rev = !rev;
            } else {
                if(d.empty()) {
                    error = true;
                    break;
                }
                if(rev) d.pop_back();
                else d.pop_front();
            }
        }
        if(error) {
            cout << "error" << '\n';
        } else {
            if(rev) reverse(d.begin(), d.end());
            cout << "[";
            for(int i = 0; i < d.size(); i++) {
                cout << d[i];
                if(i < d.size() - 1) cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}
