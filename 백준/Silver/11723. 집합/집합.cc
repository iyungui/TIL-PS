#include <bits/stdc++.h>

using namespace std;

int n, a, x;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s[0] == 'a' && s[1] == 'l') {
            a = (1 << 20) - 1;
        } else if(s[0] == 'e') {
            a = 0;
        }
        else {
            cin >> x;
            x--;
            if(s[0] == 'a' && s[1] == 'd') {
                a |= (1 << x);
            } else if(s[0] == 'r') {
                a &= ~(1 << x);
            } else if(s[0] == 'c') {
                if(a & (1 << x)) cout << 1 << '\n';
                else cout << 0 << '\n';
            } else if(s[0] == 't') {
                a ^= (1 << x);
            }
        }
    }
    return 0;
}
