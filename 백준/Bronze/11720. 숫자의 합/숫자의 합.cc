#include <bits/stdc++.h>
using namespace std;

string s;
int ret, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(char a : s) {
        ret += (int)a - '0';
    }
    cout << ret << '\n';
    return 0;
}
