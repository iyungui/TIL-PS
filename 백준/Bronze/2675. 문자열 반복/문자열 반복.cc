#include <bits/stdc++.h>
using namespace std;

int t, r;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        string ret;
        cin >> r >> s;
        for(char a : s) {
            for(int i = 0; i < r; i++) {
                ret += a;
            }
        }
        cout << ret << '\n';
    }
    cout << '\n';
    return 0;
}