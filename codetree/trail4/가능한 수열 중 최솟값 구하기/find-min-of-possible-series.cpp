#include <bits/stdc++.h>
using namespace std;

int N;
string ret;

bool chk(string& s) {
    int m = s.size();
    for(int i = 1; i <= m/2; i++) {
        string r = s.substr(m-i, i);
        string l = s.substr(m - (i*2), i);

        if(l == r) return 0;
    }
    return 1;
}

void go(int k) {
    if(k == N) {
        cout << ret << '\n';
        exit(0);
    }

    for(char c = '4'; c <= '6'; c++) {
        ret.push_back(c);
        if(chk(ret)) go(k+1);
        ret.pop_back();
    }
}

int main() {
    cin >> N;
    go(0);
    return 0;
}