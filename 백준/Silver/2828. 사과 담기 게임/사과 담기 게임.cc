#include<bits/stdc++.h>
using namespace std;

int n, m, j, l, r, ret, pos;
int main() {
    cin >> n >> m >> j;
    l = 1, r = m;
    for(int i = 0; i < j; i++) {
        cin >> pos;
        if(pos <= r && pos >= l) continue;
        if(pos < l) {
            ret += l - pos;
            l = pos; r = pos + m - 1;
        }
        else if(pos > r) {
            ret += pos - r;
            r = pos; l = pos - m + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}