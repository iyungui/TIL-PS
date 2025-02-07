#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> s;
        cout << s[0] << s[(int)s.size() - 1] << '\n';
    }
    return 0;
}
