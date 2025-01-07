#include <bits/stdc++.h>

using namespace std;

int n;
string p, a;
string pre, suf;

int main() {
    cin >> n >> p;
    int pos = (int)p.find('*');
    pre = p.substr(0, pos);
    suf = p.substr(pos + 1);
    for(int i = 0; i < n; i++) {
        cin >> a;
        if((int)pre.size() + (int)suf.size() > (int)a.size()) cout << "NE\n";
        else {
            if(pre == a.substr(0, (int)pre.size()) && suf == a.substr((int)a.size() - (int)suf.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }
    return 0;
}
