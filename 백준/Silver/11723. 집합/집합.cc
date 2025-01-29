#include <bits/stdc++.h>

using namespace std;

int n, x, a;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        
        if(s == "all") {
            a = (1 << 20) - 1;
        } else if(s == "empty") {
            a = 0;
        } else {
            cin >> x;
            x--;
            if(s == "add") {
                a |= (1 << x);
            } else if(s == "remove") {
                a &= ~(1 << x);
            } else if(s == "check") {
                if(a & (1 << x)) cout << 1 << '\n';
                else cout << 0 << '\n';
            } else if(s == "toggle") {
                a ^= (1 << x);
            }
        }
    }
    return 0;
}
