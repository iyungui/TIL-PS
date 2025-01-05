#include <bits/stdc++.h>

using namespace std;

string p, s, pre, suf;
int n;

int main() {
    cin >> n;
    cin >> p;
    
    int pos = (int)p.find('*'); // 무조건 * 있음
    pre = p.substr(0, pos);
    suf = p.substr(pos + 1);
    
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(pre.size() + suf.size() > s.size()) cout << "NE\n";
        else {
            if(s.substr(0, pre.size()) == pre && s.substr(s.size() - suf.size()) == suf) cout << "DA\n";
            else cout << "NE\n";
        }
    }
    return 0;
}
