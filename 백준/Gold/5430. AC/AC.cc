#include <bits/stdc++.h>

using namespace std;

int t, n;
string p, s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> p >> n >> s;
        string str;
        deque<int> d;
        
        int x = 0;
        for(char a : s) {
            if(a == ']' || a == '[') continue;
            else if(a >= '0' && a <= '9') {
                x = x * 10 + a - '0';
            } else {
                if(x > 0) d.push_back(x);
                x = 0;
            }
        }
        if(x > 0) d.push_back(x);
        
        bool rev = false, error = false;
        for(char a : p) {
            if(a == 'R') rev = !rev;
            else {
                if(d.empty()) {
                    error = true;
                    break;
                }
                if(rev) d.pop_back();
                else d.pop_front();
            }
        }
        
        if(error) cout << "error" << '\n';
        else {
            if(rev) reverse(d.begin(), d.end());
            cout << "[";
            for(int i = 0; i < d.size(); i++) {
                cout << d[i];
                if(i < d.size() - 1) cout << ',';
            }
            cout << "]\n";
        }
    }
    return 0;
}
